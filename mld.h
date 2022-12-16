#ifndef __MLD__
#include <assert.h>


/* Structure Data Base definition begin */

#define MAX_STRUCTURE_NAME_SIZE 128
#define MAX_FIELD_NAME_SIZE 128

// Enumeration for data types

typedef enum{
	UINT8,
	UINT32,
	INT32,
	CHAR,
	OBJ_PTR,
	VOID_PTR,
	FLOAT,
	DOUBLE,
	OBJ_STRUCT
} data_type_t;

#define OFFSETOF(struct_name, fld_name)		\
	(unsigned long)&(((struct_name *)0)->fld_name)

#define FIELD_SIZE(struct_name, fld_name)		\
	sizeof(((struct_name *)0)->fld_name)

typedef struct _struct_db_rec_ struct_db_rec_t;

//Structure to store the information of one field of a C structure
typedef struct _field_info_{
	char fname [MAX_FIELD_NAME_SIZE];							//Name of field
	data_type_t dtype;															//Data type of field
	unsigned int size;															//Size of the field
	unsigned int offset;														//Offset of field
	char nested_str_name[MAX_STRUCTURE_NAME_SIZE];	//If dtype = OBJ_PTR or OBJ_STRUCT, this is used.
} field_info_t;


//Structure to store the information of one C structure which culd have 'n_fields' fields
struct _struct_db_rec_{
	struct_db_rec_t *next;													//Pointer to the next structure in the linked list
	char struct_name[MAX_STRUCTURE_NAME_SIZE];		//key
	unsigned int ds_size;														//Size of structure
	unsigned int n_fields;														//No of fields in the structure
	field_info_t *fields;															//Pointer to the array of fields
};

//Head of Linked list representing the structure database
typedef struct _struct_db_{
	struct_db_rec_t *head;
	unsigned int count;
}struct_db_t;

//Structure Database definition ends


//Printing functions
void print_structure_rec (struct_db_rec_t *struct_rec);
void print_structure_db (struct_db_t *struct_db);

//Function to add the structure record in a structure databse
int add_structure_to_struct_db(struct_db_t *struct_db, struct_db_rec_t *struct_rec);  //returns 0 on success and -1 on failure

//Structure Registration helping APIs
#define FIELD_INFO(struct_name, fld_name, dtype,nested_str_name)	\
	{#fld_name, dtype, FIELD_SIZE(struct_name, fld_name),				\
			OFFSETOF(struct_name, fld_name), #nested_str_name}

#define REG_STRUCT(struct_db, st_name, fields_arr)							\
	do{																								\
		struct_db_rec_t *rec = calloc(1, sizeof(struct_db_rec_t));				\
		strncpy(rec->struct_name, #st_name, MAX_STRUCTURE_NAME_SIZE); \
        rec->ds_size = sizeof(st_name);													\
        rec->n_fields = sizeof(fields_arr)/sizeof(field_info_t);						\
        rec->fields = fields_arr;																\
        if(add_structure_to_struct_db(struct_db, rec)){								\
            assert(0);																				\
        }																								\
	}while(0);


#endif //__MLD__