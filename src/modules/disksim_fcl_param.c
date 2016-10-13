#include "disksim_fcl_param.h"
#include <libparam/bitvector.h>
#include "../disksim_fcl.h"
static int DISKSIM_FCL_PAGE_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_PAGE_SIZE_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_page_size = i;

}

static int DISKSIM_FCL_MAX_PAGES_PERCENT_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_MAX_PAGES_PERCENT_loader(struct fcl_parameters * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->fpa_max_pages_percent = d;

}

static int DISKSIM_FCL_BYPASS_CACHE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_BYPASS_CACHE_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_bypass_cache = i;

}

static int DISKSIM_FCL_IDLE_DETECT_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_IDLE_DETECT_TIME_loader(struct fcl_parameters * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->fpa_idle_detect_time = d;

}

static int DISKSIM_FCL_MAX_DESTAGE_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_MAX_DESTAGE_SIZE_loader(struct fcl_parameters * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->fpa_max_destage_size = d;

}

static int DISKSIM_FCL_MAX_RESIZE_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_MAX_RESIZE_SIZE_loader(struct fcl_parameters * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->fpa_max_resize_size = d;

}

static int DISKSIM_FCL_ON_DEMAND_GROUP_DESTAGE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_ON_DEMAND_GROUP_DESTAGE_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_ondemand_group_destage = i;

}

static int DISKSIM_FCL_BACKGROUND_GROUP_DESTAGE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_BACKGROUND_GROUP_DESTAGE_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_background_group_destage = i;

}

static int DISKSIM_FCL_HIT_TRACKER_DECAY_FACTOR_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_HIT_TRACKER_DECAY_FACTOR_loader(struct fcl_parameters * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->fpa_hit_tracker_decayfactor = d;

}

static int DISKSIM_FCL_HIT_TRACKER_N_SEGMENT_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_HIT_TRACKER_N_SEGMENT_SIZE_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_hit_tracker_nsegment = i;

}

static int DISKSIM_FCL_SEQUENTIAL_DETECTION_ENABLE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_SEQUENTIAL_DETECTION_ENABLE_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_seq_detection_enable = i;

}

static int DISKSIM_FCL_SEQUENTIAL_UNIT_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_SEQUENTIAL_UNIT_SIZE_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_seq_unit_size = i;

}

static int DISKSIM_FCL_FOREGROUND_QUEUE_OUTSTANDING_LENGTH_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_FOREGROUND_QUEUE_OUTSTANDING_LENGTH_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_fore_outstanding = i;

}

static int DISKSIM_FCL_BACKGROUND_QUEUE_OUTSTANDING_LENGTH_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_BACKGROUND_QUEUE_OUTSTANDING_LENGTH_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_back_outstanding = i;

}

static int DISKSIM_FCL_PARTITIONING_SCHEME_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_PARTITIONING_SCHEME_loader(struct fcl_parameters * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->fpa_partitioning_scheme = i;

}

static int DISKSIM_FCL_HDD_READ_POSITIONING_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_HDD_READ_POSITIONING_TIME_loader(struct fcl_parameters * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->fpa_hdd_crpos = d;

}

static int DISKSIM_FCL_HDD_WRITE_POSITIONING_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_HDD_WRITE_POSITIONING_TIME_loader(struct fcl_parameters * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->fpa_hdd_cwpos = d;

}

static int DISKSIM_FCL_HDD_BANDWIDTH_depend(char *bv) {
return -1;
}

static void DISKSIM_FCL_HDD_BANDWIDTH_loader(struct fcl_parameters * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->fpa_hdd_bandwidth = d;

}

void * DISKSIM_FCL_loaders[] = {
(void *)DISKSIM_FCL_PAGE_SIZE_loader,
(void *)DISKSIM_FCL_MAX_PAGES_PERCENT_loader,
(void *)DISKSIM_FCL_BYPASS_CACHE_loader,
(void *)DISKSIM_FCL_IDLE_DETECT_TIME_loader,
(void *)DISKSIM_FCL_MAX_DESTAGE_SIZE_loader,
(void *)DISKSIM_FCL_MAX_RESIZE_SIZE_loader,
(void *)DISKSIM_FCL_ON_DEMAND_GROUP_DESTAGE_loader,
(void *)DISKSIM_FCL_BACKGROUND_GROUP_DESTAGE_loader,
(void *)DISKSIM_FCL_HIT_TRACKER_DECAY_FACTOR_loader,
(void *)DISKSIM_FCL_HIT_TRACKER_N_SEGMENT_SIZE_loader,
(void *)DISKSIM_FCL_SEQUENTIAL_DETECTION_ENABLE_loader,
(void *)DISKSIM_FCL_SEQUENTIAL_UNIT_SIZE_loader,
(void *)DISKSIM_FCL_FOREGROUND_QUEUE_OUTSTANDING_LENGTH_loader,
(void *)DISKSIM_FCL_BACKGROUND_QUEUE_OUTSTANDING_LENGTH_loader,
(void *)DISKSIM_FCL_PARTITIONING_SCHEME_loader,
(void *)DISKSIM_FCL_HDD_READ_POSITIONING_TIME_loader,
(void *)DISKSIM_FCL_HDD_WRITE_POSITIONING_TIME_loader,
(void *)DISKSIM_FCL_HDD_BANDWIDTH_loader
};

lp_paramdep_t DISKSIM_FCL_deps[] = {
DISKSIM_FCL_PAGE_SIZE_depend,
DISKSIM_FCL_MAX_PAGES_PERCENT_depend,
DISKSIM_FCL_BYPASS_CACHE_depend,
DISKSIM_FCL_IDLE_DETECT_TIME_depend,
DISKSIM_FCL_MAX_DESTAGE_SIZE_depend,
DISKSIM_FCL_MAX_RESIZE_SIZE_depend,
DISKSIM_FCL_ON_DEMAND_GROUP_DESTAGE_depend,
DISKSIM_FCL_BACKGROUND_GROUP_DESTAGE_depend,
DISKSIM_FCL_HIT_TRACKER_DECAY_FACTOR_depend,
DISKSIM_FCL_HIT_TRACKER_N_SEGMENT_SIZE_depend,
DISKSIM_FCL_SEQUENTIAL_DETECTION_ENABLE_depend,
DISKSIM_FCL_SEQUENTIAL_UNIT_SIZE_depend,
DISKSIM_FCL_FOREGROUND_QUEUE_OUTSTANDING_LENGTH_depend,
DISKSIM_FCL_BACKGROUND_QUEUE_OUTSTANDING_LENGTH_depend,
DISKSIM_FCL_PARTITIONING_SCHEME_depend,
DISKSIM_FCL_HDD_READ_POSITIONING_TIME_depend,
DISKSIM_FCL_HDD_WRITE_POSITIONING_TIME_depend,
DISKSIM_FCL_HDD_BANDWIDTH_depend
};

