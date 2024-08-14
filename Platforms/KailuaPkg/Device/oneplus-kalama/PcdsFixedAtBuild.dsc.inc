[PcdsFixedAtBuild.common]
gSurfaceDuoFamilyPkgTokenSpaceGuid.PcdMipiFrameBufferWidth|1264
gSurfaceDuoFamilyPkgTokenSpaceGuid.PcdMipiFrameBufferHeight|2780

# Smbios Info
gSurfaceDuoFamilyPkgTokenSpaceGuid.PcdSmbiosSystemBrand|"OnePlus"
gSurfaceDuoFamilyPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Ace 3"
gSurfaceDuoFamilyPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"Ace 3"
gSurfaceDuoFamilyPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Ace 3"

# Necessary Addresses
gQcomPkgTokenSpaceGuid.KernelProtocolAddress|0xA703A930
gQcomPkgTokenSpaceGuid.XBLDTProtocolAddress|0xA703A0C8

[PcdsDynamicDefault.common]
gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|1264
gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|2780
gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|1264
gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|2780
gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|99     # = 1264 / EFI_GLYPH_WIDTH(8)
gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|123       # = 2780 / EFI_GLYPH_HEIGHT(19)
gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|99          # = 1264 / EFI_GLYPH_WIDTH(8)
gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|123            # = 2780 / EFI_GLYPH_HEIGHT(19)
