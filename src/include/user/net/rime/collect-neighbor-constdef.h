#ifndef __COLLECT_NEIGHBOR_COMPONENT_CONSTDEF_H__
#define __COLLECT_NEIGHBOR_COMPONENT_CONSTDEF_H__


enum COLLECT_NEIGHBOR_FUNCTION {
	FUNCTION_COLLECT_NEIGHBOR_LIST_NEW,
	FUNCTION_COLLECT_NEIGHBOR_LINK_ESTIMATE,
	FUNCTION_COLLECT_NEIGHBOR_LIST_FIND,
	FUNCTION_COLLECT_NEIGHBOR_LIST_ADD,
	FUNCTION_COLLECT_NEIGHBOR_IS_CONGESTED,
	FUNCTION_COLLECT_NEIGHBOR_LIST_BEST,
	FUNCTION_COLLECT_NEIGHBOR_LIST,
	FUNCTION_COLLECT_NEIGHBOR_SET_CONGESTED,
	FUNCTION_COLLECT_NEIGHBOR_RTMETRIC,
	FUNCTION_COLLECT_NEIGHBOR_LIST_NUM,
	FUNCTION_COLLECT_NEIGHBOR_TX,
	FUNCTION_COLLECT_NEIGHBOR_UPDATE_RTMETRIC,
	FUNCTION_COLLECT_NEIGHBOR_RX,
	FUNCTION_COLLECT_NEIGHBOR_INIT,
	FUNCTION_COLLECT_NEIGHBOR_LIST_REMOVE,
	FUNCTION_COLLECT_NEIGHBOR_LIST_PURGE,
	FUNCTION_COLLECT_NEIGHBOR_RTMETRIC_LINK_ESTIMATE,
	FUNCTION_COLLECT_NEIGHBOR_LIST_GET,
	FUNCTION_COLLECT_NEIGHBOR_TX_FAIL,
	FUNCTION_COLLECT_NEIGHBOR_LAST,
};


enum COLLECT_NEIGHBOR_PROCESSES {
	PROCESS_COLLECT_NEIGHBOR_LAST,
};


#endif /*__COLLECT_NEIGHBOR_COMPONENT_CONSTDEF_H__*/