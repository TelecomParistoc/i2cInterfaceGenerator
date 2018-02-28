#ifndef PARSER_H
#define PARSER_H

#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>
#include <stdint.h>

#define NAME_MAX_SIZE 100
#define TYPE_MAX_SIZE 20
#define CAT_MAX_SIZE 40

typedef enum location_e {
    LOCATION_FLASH,
    LOCATION_RAM,
    LOCATION_COMMAND,
    LOCATION_END /* Not a valid location value */
} location_t;

typedef struct interface_element_s {
    char name[NAME_MAX_SIZE];
    char type[TYPE_MAX_SIZE];
    char c_name[NAME_MAX_SIZE];
    char category[CAT_MAX_SIZE];
    location_t location;
    uint8_t address;
    uint8_t size;
    uint8_t read_access;
    uint8_t write_access;
    uint8_t gen_code;
    struct interface_element_s *next;
} interface_element_t;

typedef struct device_s {
    uint8_t addr;
} device_t;

extern xmlDoc* init_parsing(char* file_name);
extern interface_element_t* parse(xmlDoc* doc, device_t *device);
extern void close_parsing(xmlDoc* doc, interface_element_t* entry);

#endif
