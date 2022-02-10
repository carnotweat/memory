typedef struct multiboot_memory_map {
	unsigned int size;
	unsigned int base_addr_low,base_addr_high;
  // You can also use: unsigned long long int base_addr; if supported.
	unsigned int length_low,length_high;
  // You can also use: unsigned long long int length; if supported.
	unsigned int type;
} multiboot_memory_map_t;
 
// this is really an entry, not the entire map.
typedef multiboot_memory_map_t mmap_entry_t;
 
int main(multiboot_info* mbt, unsigned int magic) {
	...
    mmap_entry_t* entry = mbt->mmap_addr;
	while(entry < mbt->mmap_addr + mbt->mmap_length) {
		// do something with the entry
		entry = (mmap_entry_t*) ((unsigned int) entry + entry->size + sizeof(entry->size));
	}
	...
                                                     }
