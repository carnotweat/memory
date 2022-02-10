typedef struct {
  UINT32                          Type;           // EFI_MEMORY_TYPE, Field size is 32 bits followed by 32 bit pad
  UINT32                          Pad;
  EFI_PHYSICAL_ADDRESS            PhysicalStart;  // Field size is 64 bits
  EFI_VIRTUAL_ADDRESS             VirtualStart;   // Field size is 64 bits
  UINT64                          NumberOfPages;  // Field size is 64 bits
  UINT64                          Attribute;      // Field size is 64 bits
} EFI_MEMORY_DESCRIPTOR;
typedef enum {
  EfiReservedMemoryType,
  EfiLoaderCode,
  EfiLoaderData,
  EfiBootServicesCode,
  EfiBootServicesData,
  EfiRuntimeServicesCode,
  EfiRuntimeServicesData,
  EfiConventionalMemory,
  EfiUnusableMemory,
  EfiACPIReclaimMemory,
  EfiACPIMemoryNVS,
  EfiMemoryMappedIO,
  EfiMemoryMappedIOPortSpace,
  EfiPalCode,
  EfiPersistentMemory,
  EfiMaxMemoryType
} EFI_MEMORY_TYPE;
