


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


typedef struct _struct_db_rec_ struct_db_rec_t;

//Structure to store the information of one field of a C structure
typedef struct _field_info_{
	char fname [MAX_FIELD_NAME_SIZE];							//Name of field
	data_type_t dtype;															//Data type of field
	unsigned int size;															//Size of the field
	unsigned int offset;														//Offset of field
	char nested_str_name[MAX_STRUCTURE_NAME_SIZE];	//If dtype = OBJ_PTR or OBJ_STRUCT, this is used.
} field_info_t;


struct _struct_db_rec_{
	struct_db_rec_t *next;													//Pointer to the next structure in the linked list
	char struct_name[MAX_STRUCTURE_NAME_SIZE];		//key
	unsigned int ds_size;														//Size of structure
	unsigned int n_fields;														//No of fields in the structure
	field_info_t *fields;															//Pointer to the array of fields
};