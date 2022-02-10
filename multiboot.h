struct multiboot_mmap_entry
{
  multiboot_uint32_t size;
  multiboot_uint32_t addr_low;
  multiboot_uint32_t addr_high;
  multiboot_uint32_t len_low;
  multiboot_uint32_t len_high;
#define MULTIBOOT_MEMORY_AVAILABLE              1
#define MULTIBOOT_MEMORY_RESERVED               2
#define MULTIBOOT_MEMORY_ACPI_RECLAIMABLE       3
#define MULTIBOOT_MEMORY_NVS                    4
#define MULTIBOOT_MEMORY_BADRAM                 5
  multiboot_uint32_t type;
} __attribute__((packed));
typedef struct multiboot_mmap_entry multiboot_memory_map_t;
