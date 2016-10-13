
#ifndef _DISKSIM_FCL_PARAM_H
#define _DISKSIM_FCL_PARAM_H  

#include <libparam/libparam.h>
#ifdef __cplusplus
extern"C"{
#endif
struct dm_disk_if;

/* prototype for disksim_fcl param loader function */
int disksim_fcl_loadparams(struct lp_block *b, int *num);

typedef enum {
   DISKSIM_FCL_PAGE_SIZE,
   DISKSIM_FCL_MAX_PAGES_PERCENT,
   DISKSIM_FCL_BYPASS_CACHE,
   DISKSIM_FCL_IDLE_DETECT_TIME,
   DISKSIM_FCL_MAX_DESTAGE_SIZE,
   DISKSIM_FCL_MAX_RESIZE_SIZE,
   DISKSIM_FCL_ON_DEMAND_GROUP_DESTAGE,
   DISKSIM_FCL_BACKGROUND_GROUP_DESTAGE,
   DISKSIM_FCL_HIT_TRACKER_DECAY_FACTOR,
   DISKSIM_FCL_HIT_TRACKER_N_SEGMENT_SIZE,
   DISKSIM_FCL_SEQUENTIAL_DETECTION_ENABLE,
   DISKSIM_FCL_SEQUENTIAL_UNIT_SIZE,
   DISKSIM_FCL_FOREGROUND_QUEUE_OUTSTANDING_LENGTH,
   DISKSIM_FCL_BACKGROUND_QUEUE_OUTSTANDING_LENGTH,
   DISKSIM_FCL_PARTITIONING_SCHEME,
   DISKSIM_FCL_HDD_READ_POSITIONING_TIME,
   DISKSIM_FCL_HDD_WRITE_POSITIONING_TIME,
   DISKSIM_FCL_HDD_BANDWIDTH
} disksim_fcl_param_t;

#define DISKSIM_FCL_MAX_PARAM		DISKSIM_FCL_HDD_BANDWIDTH
extern void * DISKSIM_FCL_loaders[];
extern lp_paramdep_t DISKSIM_FCL_deps[];


static struct lp_varspec disksim_fcl_params [] = {
   {"Page Size", I, 1 },
   {"Max Pages Percent", D, 1 },
   {"Bypass Cache", I, 1 },
   {"Idle Detect Time", D, 1 },
   {"Max Destage Size", D, 1 },
   {"Max Resize Size", D, 1 },
   {"On-demand Group Destage", I, 1 },
   {"Background Group Destage", I, 1 },
   {"Hit Tracker Decay Factor", D, 1 },
   {"Hit Tracker N-Segment Size", I, 1 },
   {"Sequential Detection Enable", I, 1 },
   {"Sequential Unit Size", I, 1 },
   {"Foreground Queue Outstanding Length", I, 1 },
   {"Background Queue Outstanding Length", I, 1 },
   {"Partitioning Scheme", I, 1 },
   {"HDD Read Positioning Time", D, 1 },
   {"HDD Write Positioning Time", D, 1 },
   {"HDD Bandwidth", D, 1 },
   {0,0,0}
};
#define DISKSIM_FCL_MAX 18
static struct lp_mod disksim_fcl_mod = { "disksim_fcl", disksim_fcl_params, DISKSIM_FCL_MAX, (lp_modloader_t)disksim_fcl_loadparams,  0, 0, DISKSIM_FCL_loaders, DISKSIM_FCL_deps };


#ifdef __cplusplus
}
#endif
#endif // _DISKSIM_FCL_PARAM_H
