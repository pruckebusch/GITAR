#ifndef QUEUE_H
#define QUEUE_H

/*

A queue consists of entries.
Each queue entry has a linked list with queue items.
Queue items can be added (linked) to a queue entry. They are provided by each component that interacts with a packet (rx or tx).
A queue item is allocated by the component that owns the item.
This component should also allocate the neccesary buffer space necessary for storing the protocol header of the component

*/

#define QUEUE_META_ITEM_ID 0
#define QUEUE_OWNER_ID 0
#define NUM_QUEUE_ENTRIES 10

typedef uint8_t queue_owner_id;
typedef uint8_t queue_entry_id;
typedef uint8_t queue_item_id;
typedef uint8_t attr_type;

typedef struct queue_item {
	struct queue_item* next;
	void* item_buf;
	uint8_t item_len;
	queue_item_id item_id;
	queue_owner_id item_owner;
	uint8_t (*compact)(queue_entry_id, struct queue_item*, void* buf); // this function has to be provided by the item_owner and allows the radio controller to compactize the memory
} queue_item_t;

typedef struct attribute {
	struct attribute* next;
	attr_type type;
	uint8_t len;
	void* val;
} attribute_t;

/*

This function initializes the queue.
A meta data queue_item will be added as first element to each queue entry.
The owner of the entry will be initialized to 0 == QUEUE_OWNER_ID

*/
queue_init();


/*

This function allows protocols, applications or radio controllers to allocate a free queue entry.
This queue entry can than be used for adding a queue item to it when
(a) a radio controller receives a packet.
(b) an application or a protocol wants to send a NEW packet
(c) a protocol or application that wants to forward an OLD packet by creating a NEW packet and sending it via another communication interface

*/
queue_entry_id queue_allocate_entry(queue_owner_id owner);

error_t queue_release_entry(queue_entry_id entry, queue_owner_id owner);

error_t queue_clear_entry(queue_entry_id entry, queue_owner_id owner);

void queue_entry_append_item(queue_entry_id entry, queue_item_t* item);

void queue_entry_push_item(queue_entry_id entry, queue_item_t* item);

queue_item_t* queue_entry_get_item(queue_entry_id entry, queue_item_id item_id);

void queue_entry_insert_item(queue_entry_id entry, queue_item_t* item, queue_item_t* prev, queue_item_t* next);

void queue_entry_insert_before(queue_entry_id entry, queue_item_t* item, queue_item_t* prev, queue_item_t* next);



#endif /*QUEUE_H*/
