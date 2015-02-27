#include "lib/queue/queue.h"

typedef struct queue_entry {
	LIST_STRUCT(items);
	LIST_STRUCT(attributes);
} queue_entry_t;

typedef struct queue {
	queue_owner_id owners[NUM_QUEUE_ENTRIES];
	queue_entry_t entries[NUM_QUEUE_ENTRIES];
} queue_t

queue_t entry_queue;

void queue_init(){
	int i;
	for(i = 0; i< NUM_QUEUE_ENTRIES ; i++){
		LIST_STRUCT_INIT(&entry_queue.entries[i], items);
		LIST_STRUCT_INIT(&entry_queue.entries[i], attributes);
		entry_queue.owners[i] = QUEUE_OWNER_ID;
	}
}

queue_entry_id queue_allocate_entry(queue_owner_id owner){
	int i;
	for(i = 0; i< NUM_QUEUE_ENTRIES ; i++){
		if(entry_queue.owners[i] == QUEUE_OWNER_ID){
			entry_queue.owners[i] = owner;
			return i;
		}
	}
	return -1;
}

error_t queue_release_entry(queue_entry_id entry, queue_owner_id owner){
	int i;
	for(i = 0; i< NUM_QUEUE_ENTRIES ; i++){
		if(entry_queue.owners[i] == owner){
			entry_queue.owners[i] = QUEUE_OWNER_ID;
			list_init(entry_queue.entries[i].items);
			list_init(entry_queue.entries[i].attributes);
			return SUCCESS;
		}
	}
	return FAIL;
}

error_t queue_clear_entry(queue_entry_id entry, queue_owner_id owner){
	int i;
	for(i = 0; i< NUM_QUEUE_ENTRIES ; i++){
		if(entry_queue.owners[i] == owner){
			list_init(entry_queue.entries[i].items);
			list_init(entry_queue.entries[i].attributes);
			return SUCCESS;
		}
	}
	return FAIL;
}

void queue_entry_append_item(queue_entry_id entry, queue_item_t* item){
	list_add(entry_queue.entries[entry].items, item);
}

void queue_entry_push_item(queue_entry_id entry, queue_item_t* item){
	list_push(entry_queue.entries[entry].items, item);
}

queue_item_t* queue_entry_get_item(queue_entry_id entry, queue_item_id item){
	void* i = list_head(entry_queue.entries[entry].items);
	while(i!=NULL){
		queue_item_t* qitem = (queue_item_t*) i;
		if(qitem->item_id == item){
			return qitem;
		}
		i = list_item_next(i);
	}
	return NULL;
}

attribute_t* queue_entry_get_attr(queue_entry_id entry, attr_type type, uint8_t len){
	void* i = list_head(entry_queue.entries[entry].attributes);
	while(i!=NULL){
		attribute_t* attr = (attribute_t*) i;
		if(attr->type == type && attr->len == len){
			return attr;
		} else if(attr->type < type){
			i = list_item_next(i);
		} else {
			i = NULL;
		}
	}
	return NULL;
}

error_t queue_entry_add_attr(queue_entry_id entry, attribute_t* attr){
	attribute_t* curr = (attribute_t*) list_head(entry_queue.entries[entry].attributes);
	attribute_t* next = (attribute_t*) list_item_next(curr);
	if(curr == NULL){
		list_add(entry_queue.entries[entry].attributes, attr);
		return SUCCESS;
	}
	if(curr->type > attr->type){
		list_push(entry_queue.entries[entry].attributes, attr);
		return SUCCESS;
	} else if(curr->type == attr->type){
		list_pop(entry_queue.entries[entry].attributes);
		list_push(entry_queue.entries[entry].attributes, attr);
		return SUCCESS;
	}
	if(next == NULL){
		list_add(entry_queue.entries[entry].attributes, attr);
		return SUCCESS;
	}
	while(curr != NULL && next != NULL){
		if(attr->type < next->type){
			list_insert(entry_queue.entries[entry].attributes, curr , attr);
			return SUCCESS;
		} else if(attr->type == next->type){
			list_remove(entry_queue.entries[entry].attributes, next);
			list_insert(entry_queue.entries[entry].attributes, curr , attr);
			return SUCCESS;
		}
		curr = next;
		next = (attribute_t*) list_item_next(curr);
	}	
	if(next == NULL){
		list_add(entry_queue.entries[entry].attributes, attr);
	}
	return SUCCESS;
}
