// running in real mode may require:
__asm__(".code16gcc\n");
 
// SMAP entry structure
#include <stdint.h>
typedef struct SMAP_entry {
 
	uint32_t BaseL; // base address uint64_t
	uint32_t BaseH;
	uint32_t LengthL; // length uint64_t
	uint32_t LengthH;
	uint32_t Type; // entry Type
	uint32_t ACPI; // extended
 
}__attribute__((packed)) SMAP_entry_t;
 
// load memory map to buffer - note: regparm(3) avoids stack issues with gcc in real mode
int __attribute__((noinline)) __attribute__((regparm(3))) detectMemory(SMAP_entry_t* buffer, int maxentries)
{
	uint32_t contID = 0;
	int entries = 0, signature, bytes;
	do 
	{
		__asm__ __volatile__ ("int  $0x15" 
				: "=a"(signature), "=c"(bytes), "=b"(contID)
				: "a"(0xE820), "b"(contID), "c"(24), "d"(0x534D4150), "D"(buffer));
		if (signature != 0x534D4150) 
			return -1; // error
		if (bytes > 20 && (buffer->ACPI & 0x0001) == 0)
		{
			// ignore this entry
		}
		else {
			buffer++;
			entries++;
		}
	} 
	while (contID != 0 && entries < maxentries);
	return entries;
}
 
// in your main routine - memory map is stored in 0000:1000 - 0000:2FFF for example
[...] {
	[...]
	SMAP_entry_t* smap = (SMAP_entry_t*) 0x1000;
	const int smap_size = 0x2000;
 
	int entry_count = detectMemory(smap, smap_size / sizeof(SMAP_entry_t));
 
	if (entry_count == -1) {
		// error - halt system and/or show error message
		[...]
	} else {
		// process memory map
		[...]
	}
}

