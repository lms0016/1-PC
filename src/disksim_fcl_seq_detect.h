
/*
* Flash Cache Layer (FCL) (Version 1.0) 
*
* Author		: Yongseok Oh (ysoh@uos.ac.kr)
* Date			: 18/06/2012  
* Description	: The header file 
* File Name		: disksim_fcl_seq_detect.h
*/

#define prize_alpha 0.5 // alpha value of formula

struct sequential_detector { 
	int sd_startblk;
	int sd_length;
	int sd_seq_size;
	int	sd_enable;
};

typedef int key_t;
typedef int data_t;

typedef enum color_t {
    RED = 0,
    BLACK = 1
} color_t;

typedef struct rb_node_t {
    struct rb_node_t *left, *right, *parent;
    key_t key; // foxtodo: blkno
  //  data_t data;
    color_t color;
    int rCnt, wCnt, length;
    int inSSD;
    double prize;
} rb_node_t; 


void sd_init( );
void sd_exit( );
int  sd_seq_detection ( int blkno, int length );
int sd_is_seq_io ( int blkno );

static rb_node_t* rb_new_node(key_t key, int length, int flags, int inSSD);
static rb_node_t* rb_rotate_left(rb_node_t* node, rb_node_t* root);
static rb_node_t* rb_rotate_right(rb_node_t* node, rb_node_t* root);
static rb_node_t* rb_insert_rebalance(rb_node_t *node, rb_node_t *root);
static rb_node_t* rb_erase_rebalance(rb_node_t *node, rb_node_t *parent, rb_node_t *root);
static rb_node_t* rb_search_auxiliary(key_t key, rb_node_t* root, rb_node_t** save);
rb_node_t* rb_insert(int key, double base, int length, int flags, int inSSD, rb_node_t* root, rb_node_t** save);
rb_node_t* rb_search(key_t key, rb_node_t* root);
rb_node_t* rb_erase(key_t key, rb_node_t* root);

int get_nodeCnt(); 
double calculate_prize(int blkno, double base, int length, int flags, int inSSD ); // use blkno to find the prize node and calculate the prize value 


