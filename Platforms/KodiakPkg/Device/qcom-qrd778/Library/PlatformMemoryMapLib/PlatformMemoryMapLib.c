#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Name               Address     Length      HobOption        ResourceAttribute    ArmAttributes
                                                          ResourceType          MemoryType */
    /* DDR Regions */
    /* DDR Bank 0 Start */
    // Protect HYP, TZApps/QSEE, And move Display Framebuffer region.
    { "HYP",               0x80000000, 0x00600000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK_XN },
    { "BOOT",              0x80600000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN },
    { "AOP CMD",           0x80800000, 0x00060000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN },
    { "AOP CMD DB",        0x80860000, 0x00020000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN },
    { "Reserved",          0x80880000, 0x00004000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN },
    { "XBL Log Buffer",    0x80884000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN },
    { "GPU PRR",           0x80894000, 0x00001000, AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN },
    { "HLOS1",             0x80895000, 0x0000F000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN },
    { "TGCM",              0x808A4000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN },
    { "HLOS2",             0x808B4000, 0x0004B000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN },
    { "APSS",              0x808FF000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN },
    { "SMEM",              0x80900000, 0x00200000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN },
    { "CPUCP",             0x80B00000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN },
    { "WLAN FW",           0x80C00000, 0x00C00000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN },
    { "LPASS_ML",          0x81800000, 0x00F00000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN },
    { "CDSP Secure Heap",  0x82700000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN },
    { "Sched Heap",        0x82710000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN },
    { "HLOS3",             0x82B10000, 0x017F0000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN },
    { "PIL Reserved",      0x84300000, 0x17A00000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN },
    { "RAM Partition",     0x9BD00000, 0x03300000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN },
    { "UEFI FD",           0x9F000000, 0x00500000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK },
    { "SEC Heap",          0x9F500000, 0x0008C000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN },
    { "CPU Vectors",       0x9F58C000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK },
    { "MMU PageTables",    0x9F58D000, 0x00003000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN },
    { "UEFI Stack",        0x9F590000, 0x00067000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN },
    { "Log Buffer",        0x9F5F7000, 0x00008000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN },
    { "Info Blk",          0x9F5FF000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN },
    { "HLOS4",             0x9F600000, 0x00900000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN },
    { "FV Region",         0x9FF00000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN },
    { "USB UCSI Temp",     0xA0000000, 0x00002000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN },
    { "HLOS5",             0xA0002000, 0x007FE000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN },
    // Is this OK? MPSS Located in Kernel Region, which is protected by tz.
    { "MPSS_EFS",          0xA0800000, 0x00300000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, UNCACHED_UNBUFFERED_XN },
//    { "HLOS6",             0xA0B00000, 0x1AB00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN },
    { "HLOS6",             0xA0B00000, 0x0F500000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN },
    { "HYP RESERVED",      0xB0000000, 0x10000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN },

    /* Memory Hole */
    // 0xB9300000 - 0xC0000000
    // Size: 0x6D00000

    { "Reserv",            0xC0000000, 0x01000000, NoHob,  SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE },
    { "TAGS",              0xC0100000, 0x01200000, NoHob,  SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE },
    { "QTEE",              0xC1300000, 0x00500000, NoHob,  SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE },
    { "TZApps Reserved",   0xC1800000, 0x03900000, NoHob,  SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE },
    { "DBI Dump",          0xC5100000, 0x00F00000, NoHob,  MMAP_IO, INITIALIZED, Conv, UNCACHED_UNBUFFERED_XN },
    { "HLOS7",             0xC6000000, 0x00500000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN },
    { "ADSP RPC",          0xC6500000, 0x00800000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED_XN },
    { "Guest VM",          0xD0000000, 0x10000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN },
    { "DXE Heap",          0xD0C00000, 0x0F400000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    { "Display Reserved",  0xE1000000, 0x02400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN },
    { "APSS Ext",          0xE3400000, 0x01700000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN },

// Ram Partitions for 8GB Devices
//  0xE4B00000 - 0x280000000

#if USE_MEMORY_FOR_SERIAL_OUTPUT == 1
    { "PStore",            0xE4B00000, 0x00400000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN},
    { "RAM Partition",     0xE4B40000, 0x9B4C0000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
#else
    { "RAM Partition",     0xE4B00000, 0x9B500000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
#endif

    // Mapped 4GB till Here.
    { "RAM Partition",     0x180000000, 0x80000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
    { "RAM Partition",     0x200000000, 0x80000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},

// Mapped 8GB till Here

    // TODO Fix EnvDxe and Apply RamPartitionDxe.

    /* Other memory regions */
    { "IMEM Base",          0x14680000, 0x0002B000, NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    { "IMEM Cookie Base",   0x146AA000, 0x00001000, AddDev, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},

    /* Register regions */
    { "IPC_ROUTER_TOP",     0x00400000, 0x00100000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "SECURITY CONTROL",   0x00780000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "QUP",                0x00900000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "PRNG_CFG_PRNG",      0x010D0000, 0x00010000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "CRYPTO0 CRYPTO",     0x01DC0000, 0x00040000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "TCSR_TCSR_REGS",     0x01FC0000, 0x00030000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "PERIPH_SS_SDC1",     0x007C0000, 0x00100000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "PERIPH_SS",          0x08800000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "USB",                0x0A600000, 0x04000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "AOSS",               0x0B000000, 0x04000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "TLMM",               0x0F100000, 0x00300000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "SMMU",               0x15000000, 0x00200000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "APSS_HM",            0x17800000, 0x00E00000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "PCIE_1_AXI",         0x40000000, 0x02000000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    { "PCIE_1_AHB",         0x01C08000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},

    /* Terminator for MMU */
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
  return gDeviceMemoryDescriptorEx;
}
