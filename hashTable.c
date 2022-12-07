#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NAME 255
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFUL)

typedef struct {
	char name[MAX_NAME];
	int age;
} person;

unsigned int hash(char *name){
	int len = strnlen(name, MAX_NAME);
	unsigned int hash_value = 0;
	for (int i = 0; i < len; ++i) {
		hash_value += name[i];
		hash_value = (hash_value*name[i]) % TABLE_SIZE;
	}
	return hash_value;
}

person * hashTable[TABLE_SIZE];

void initTable(){
	for (int i = 0; i < TABLE_SIZE; ++i) {
		hashTable[i] = NULL;
	}
}

void printTable(){
	for (int i = 0; i < TABLE_SIZE; ++i) {
		if(hashTable[i] == NULL) printf("\t%i\t----\n", i);
		else if (hashTable[i] == DELETED_NODE){
			printf("\t%i\t---<deleted>\n", i);
		} else {
		
			printf("\t%i\t%s\n", i, hashTable[i]->name);
		}
	}
}

bool insertIntoHashTable(person *p){
	if(p == NULL) return false;
	int index = hash(p->name);
	for (int i = 0; i < TABLE_SIZE; ++i) {
		int try = (i+index) % TABLE_SIZE;
		if(hashTable[try] == NULL || hashTable[try] == DELETED_NODE){
			hashTable[try] = p;
			return true;
		}
	}
	return true;
}

person *lookupInTable(char *name){
	int index = hash(name);
	for (int i = 0; i < TABLE_SIZE; ++i) {
		int try = (i+index) % TABLE_SIZE;
		if(hashTable[try] == NULL) return false;
		if(hashTable[try] == DELETED_NODE) continue;
		if(strncmp(name, hashTable[try]->name, MAX_NAME) == 0) return hashTable[try];
	}
	return NULL;
}

person *deleteFromTable(char *name){
	int index = hash(name);
	for (int i = 0; i < TABLE_SIZE; ++i) {
		int try = (i+index) % TABLE_SIZE;
		if(hashTable[try] == NULL) return NULL;
		if(hashTable[try] == DELETED_NODE) continue;
		if(strncmp(name, hashTable[try]->name, MAX_NAME) == 0) {
			person *tmp = hashTable[try];
			hashTable[try] = DELETED_NODE;
			return tmp;
		} else return NULL;
	}
	return NULL;
}

int main(int argc, char *argv[]){

	person kate = {.name="Kate", .age=27};
	person kyle = {.name="Kyle", .age=21};
	person john = {.name="John", .age=25};
	person jenny = {.name="Jenny", .age=31};
	person lili = {.name="Lili", .age=22};

	initTable();
	insertIntoHashTable(&kate);
	insertIntoHashTable(&kyle);
	insertIntoHashTable(&john);
	insertIntoHashTable(&jenny);
	insertIntoHashTable(&lili);

	deleteFromTable("Kyle");

	/*person *tmp = lookupInTable("John");*/
	/*printf("\t%p\n", tmp);*/
	/*tmp = lookupInTable("George");*/
	/*printf("\t%p\n", tmp);*/

	printTable();

	/*printf("Kate => %u\n", hash("Kate"));*/
	/*printf("Kyle => %u\n", hash("Kyle"));*/
	/*printf("Jame => %u\n", hash("Jame"));*/
	/*printf("Jaime => %u\n", hash("Jaime"));*/
	/*printf("John => %u\n", hash("John"));*/
	return 0;
}
