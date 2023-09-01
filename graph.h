/*
 *
 * Filename:        graph.h
 * Created by:      Lexi Blair
 * Last edited:     8/31/2023
 * 
 * Description:     This file contains the definition of all structures required to create a NetworkGraph
 * Compiler:        gcc 
 * 
 */


#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <assert.h>
#include "gluethread/glthread.h"

#define NODE_NAME_SIZE   16
#define IF_NAME_SIZE     16
#define MAX_INTF_PER_NODE   10

// forward declarations 
typedef struct node_ node_t;
typedef struct link_ link_t;

typedef struct interface_ {

    char interface_name[IF_NAME_SIZE];
    struct node_ * att_node;
    struct link_ * link;

} interface_t;

struct link_ {
    interface_t intf1;
    interface_t intf2;
    unsigned int cost;

};

struct node_ {
    char node_name[NODE_NAME_SIZE];
    interface_t *intf[MAX_INTF_PER_NODE];
    glthread_t graph_glue;
};


typedef struct graph_ {
    char topology_name[32];
    glthread_t node_list;
} graph_t;

/* return pointer to the nbr node which is connected to the interface */
static inline node_t * 
get_nbr_node(interface_t *interface){

    assert(interface->att_node);
    assert(interface->link);

    link_t *link = interface->link;

    if (&link->intf1 == interface)
        return link->intf2.att_node;
    else 
        return link->intf1.att_node;

}

// return index of first empty slot in interface array for given node
static inline int
get_node_intf_available_slot(node_t *node){
    
    assert(node->intf);

    for (int i = 0; i < MAX_INTF_PER_NODE; i++){
        if (!node->intf[i])
            return i;
    } 
    return -1;
}

#endif