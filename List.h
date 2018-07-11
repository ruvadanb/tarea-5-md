/*
 * List.h
 *
 *  Created on: 10/07/2018
 *      Author: Momo
 */

#ifndef LIST_H_
#define LIST_H_
typedef void* Type;
typedef struct strList* List;


List list_create();
int list_size(List who);
boolean list_add(List who, Type data);
Type list_get(List who, int p);
void list_set(List who, Type, int p);
Type list_remove(List who, int p);
boolean list_insert(List who, int p, Type value);
void list_destroy(List who);


#endif /* LIST_H_ */
