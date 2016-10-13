
/*
* Flash Cache Layer (FCL) (Version 1.0) 
*
* Author		: Yongseok Oh (ysoh@uos.ac.kr)
* Date			: 18/06/2012  
* Description	: The sequential I/O detector program
* File Name		: disksim_fcl_seq_detect.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "disksim_fcl_seq_detect.h" 
#include "disksim_global.h"

struct sequential_detector *seq_detector;
rb_node_t* root = NULL;
int nodeCnt = 0;

int sd_is_seq_io ( int blkno ) {
	int startblk = seq_detector->sd_startblk;
	int lastblk = startblk + seq_detector->sd_length;
	int seq = 0;

	if ( !seq_detector->sd_enable ) 
		return 0;

	if ( seq_detector->sd_length >= seq_detector->sd_seq_size &&
		 startblk <= blkno && lastblk >= blkno )
	{
		//printf (" Sequential I/O = %d \n", blkno );
		seq = 1;
	} else {

		//printf (" Non-Sequential I/O = %d \n", blkno );
	}		

	return seq;

}
int sd_seq_detection ( int blkno, int length ) {
	int seq = 0;

	if ( !seq_detector->sd_enable ) 
		return 0;

	if ( seq_detector->sd_startblk + seq_detector->sd_length != blkno ) {

		seq_detector->sd_startblk = blkno;
		seq_detector->sd_length = 0;

	} 

	seq_detector->sd_length += length;

	if ( seq_detector->sd_length >= seq_detector->sd_seq_size ) {
		seq = 1;
		/* 
		   printf ( " %f Seq detection: blkno = %d, length = %d \n", 
				   					simtime,
									seq_detector->sd_startblk,
									seq_detector->sd_length );
		//*/
	}

	return seq;

} 

void sd_init ( int enable, int seq_unit_sectors ){
	seq_detector = (struct sequential_detector *) malloc ( sizeof ( struct sequential_detector) );
	memset ( seq_detector, 0x00, sizeof ( struct sequential_detector ) );
	seq_detector->sd_seq_size = seq_unit_sectors;
	seq_detector->sd_enable = enable;
	printf("alpha = %.2f\n", prize_alpha);
}
  
void sd_exit () { 
	free ( seq_detector );
}

static rb_node_t* rb_new_node(key_t key, int length, int flags, int inSSD) {
    nodeCnt++;
    rb_node_t *node = (rb_node_t*)malloc(sizeof(struct rb_node_t));
    if (!node) {
		printf("malloc error!\n");
	    exit(-1);
    }
    node->key = key; // blkno
//    node->data = data;
    if (flags == 0) {
        node->rCnt = 0;
        node->wCnt = 1;
    } else {
	node->rCnt = 1;
	node->wCnt = 0;
    }
    node->length = length;
    node->inSSD = inSSD;
    node->prize = 0.0;
    return node;
} // end rb_new_node

/*-----------------------------------------------------------
|   node           right
|   / \    ==>     / \
|   a  right     node  y
|       / \           / \
|       b  y         a   b
 -----------------------------------------------------------*/

 static rb_node_t* rb_rotate_left(rb_node_t* node, rb_node_t* root) {
    rb_node_t* right = node->right;
    if ((node->right = right->left)) {
		right->left->parent = node;
    }
    right->left = node;
    if ((right->parent = node->parent)) {
        if (node == node->parent->right) {
            node->parent->right = right;
        } else {
            node->parent->left = right;
        }
    } else {
        root = right;
    }
    node->parent = right;
    return root;
} // rb_rotate_left

/*-----------------------------------------------------------
|       node           left
|       / \            / \
|    left  y   ==>    a   node
|   / \               / \
|  a   b             b   y
-----------------------------------------------------------*/

static rb_node_t* rb_rotate_right(rb_node_t* node, rb_node_t* root) {
    rb_node_t* left = node->left;
    if ((node->left = left->right)) {
		left->right->parent = node;
    }
    left->right = node;
    if ((left->parent = node->parent)) {
        if (node == node->parent->right) {
            node->parent->right = left;
        } else {
            node->parent->left = left;
        }
    } else {
        root = left;
    }
    node->parent = left;
    return root;
} // end rb_rotate_right

static rb_node_t* rb_insert_rebalance(rb_node_t *node, rb_node_t *root) {
    rb_node_t *parent, *gparent, *uncle, *tmp;
    while ((parent = node->parent) && parent->color == RED) {
        gparent = parent->parent;
        if (parent == gparent->left) {
            uncle = gparent->right;
            if (uncle && uncle->color == RED) {
                uncle->color = BLACK;
                parent->color = BLACK;
                gparent->color = RED;
                node = gparent;
            } else {
                if (parent->right == node) {
                    root = rb_rotate_left(parent, root);
                    tmp = parent;
                    parent = node;
                    node = tmp;
                }
                parent->color = BLACK;
                gparent->color = RED;
                root = rb_rotate_right(gparent, root);
            }
		} else {
            uncle = gparent->left;
            if (uncle && uncle->color == RED) {
                uncle->color = BLACK;
                parent->color = BLACK;
                gparent->color = RED;
                node = gparent;
            } else {
                if (parent->left == node) {
                    root = rb_rotate_right(parent, root);
                    tmp = parent;
                    parent = node;
                    node = tmp;
                }
                parent->color = BLACK;
                gparent->color = RED;
                root = rb_rotate_left(gparent, root);
            }
        }
    }
    root->color = BLACK;
    return root;
} // end rb_insert_rebalance

static rb_node_t* rb_erase_rebalance(rb_node_t *node, rb_node_t *parent, rb_node_t *root) {
    rb_node_t *other, *o_left, *o_right;
    while ((!node || node->color == BLACK) && node != root) {
        if (parent->left == node) {
            other = parent->right;
            if (other->color == RED) {
                other->color = BLACK;
                parent->color = RED;
                root = rb_rotate_left(parent, root);
                other = parent->right;
            }
            if ((!other->left || other->left->color == BLACK) &&
                (!other->right || other->right->color == BLACK)) {
                other->color = RED;
                node = parent;
                parent = node->parent;
            } else {
                if (!other->right || other->right->color == BLACK) {
                    if ((o_left = other->left)) {
                        o_left->color = BLACK;
                    }
                    other->color = RED;
                    root = rb_rotate_right(other, root);
                    other = parent->right;
                }
                other->color = parent->color;
                parent->color = BLACK;
                if (other->right) {
                    other->right->color = BLACK;
                }
                root = rb_rotate_left(parent, root);
                node = root;
                break;
            }
        } else {
            other = parent->left;
            if (other->color == RED) {
                other->color = BLACK;
                parent->color = RED;
                root = rb_rotate_right(parent, root);
                other = parent->left;
            }
            if ((!other->left || other->left->color == BLACK) &&
                (!other->right || other->right->color == BLACK)) {
                other->color = RED;
                node = parent;
                parent = node->parent;
            } else {
                if (!other->left || other->left->color == BLACK) {
                    if ((o_right = other->right)) {
                        o_right->color = BLACK;
                    }
                    other->color = RED;
                    root = rb_rotate_left(other, root);
                    other = parent->left;
                }
                other->color = parent->color;
                parent->color = BLACK;
                if (other->left) {
                    other->left->color = BLACK;
                }
                root = rb_rotate_right(parent, root);
                node = root;
                break;
            }
        }
    }
    if (node) {
        node->color = BLACK;
    }
    return root;
} // end rb_erase_rebalance

static rb_node_t* rb_search_auxiliary(key_t key, rb_node_t* root, rb_node_t** save) {	
    rb_node_t *node = root, *parent = NULL;
    int ret;
    while (node) {
        parent = node;
        ret = node->key - key;
        if (0 < ret) {
            node = node->left;
        } else if (0 > ret) {
            node = node->right;
        } else {
            return node;
        }
    }
    if (save) {
        *save = parent;
    }
    return NULL;
} // end rb_search_auxiliary


/*
 	cond_1 		cond_2			cond_3  		cond_4
	----		  ----			   ----			--------
	  --------	--------             --------   		  ----         
*/

rb_node_t* rb_insert(int key, double base, int length, int flags, int inSSD, rb_node_t* root, rb_node_t** save) {
    rb_node_t *parent = NULL, *node;
    parent = NULL;
    if ((node = rb_search_auxiliary(key, root, &parent))) { 
        return root; 
    }
    node = rb_new_node(key, length, flags, inSSD); 
    node->parent = parent; 
    node->left = node->right = NULL; 
    node->color = RED; 
    if (parent) {
        if (parent->key > key) { 
            parent->left = node;
        } else {
            parent->right = node;
        }
    } else {
        root = node;
    }
    root = rb_insert_rebalance(node, root);
    if (save) {
        *save = node;
    }
    return root;
} // end rb_insert

rb_node_t* rb_search(key_t key, rb_node_t* root) { 
    return rb_search_auxiliary(key, root, NULL);
} // end rb_search

rb_node_t* rb_erase(key_t key, rb_node_t *root) {
    nodeCnt--;
    rb_node_t *child, *parent, *old, *left, *node;
    color_t color;
    if (!(node = rb_search_auxiliary(key, root, NULL))) {
        printf("key %d is not exist!\n", key);
        return root;
    }
    old = node;
    if (node->left && node->right) { 
        node = node->right;
        while ((left = node->left) != NULL) { 
            node = left;
        }
        child = node->right; 
        parent = node->parent; 
        color = node->color; 
        if (child) {
            child->parent = parent;
        }
        if (parent) {
            if (parent->left == node) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
        if (node->parent == old) {
            parent = node;
        }
        node->parent = old->parent;
        node->color = old->color;
        node->right = old->right;
        node->left = old->left;
        if (old->parent) {
            if (old->parent->left == old) {
                old->parent->left = node;
            } else {
                old->parent->right = node;
            }
        } else {
            root = node;
        }
        old->left->parent = node;
        if (old->right) {
            old->right->parent = node;
        }
    } else {
        if (!node->left) {
            child = node->right;
        } else if (!node->right) {
            child = node->left;
        }
        parent = node->parent;
        color = node->color;
        if (child) {
            child->parent = parent;
        }
        if (parent) {
            if (parent->left == node) {
                parent->left = child;   
            }
            else {
                parent->right = child;
            }
        } else {
            root = child;
        }
    }
    free(old);
    if (color == BLACK) {
        root = rb_erase_rebalance(child, parent, root);
    }
    return root;
} // end rb_erase

int get_nodeCnt( ) {
	return nodeCnt;
}

double calculate_prize(int key, double base, int length, int flags, int inSSD ) { 
	rb_node_t *node = NULL, *tmp = NULL; 
	node = NULL, tmp = NULL;
	if ((node = rb_search(key, root))) { // blkno exist!
		if ( node ) {
			if ( flags == 0 ) { // write
				node->wCnt++; 
			} else {
				node->rCnt++;
			}
			node->length = length;
			node->inSSD = inSSD;
			return node->prize = prize_alpha * (node->rCnt+1)/(node->wCnt*node->length+1) + (1-prize_alpha)*base; // calculating prize value
		} else {
			printf(" check error\n");
			return 0.0;
		} 
	} else { // blkno not exist!
		root = rb_insert(key, base, length, flags, inSSD, root, &tmp);
		if ( tmp ) {
			return tmp->prize = prize_alpha * (tmp->rCnt+1)/(tmp->wCnt*tmp->length+1) + (1-prize_alpha)*base;	
		} else {
			printf( "insert error\n");
			return 0.0;		
		}
	}
}
