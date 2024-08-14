from pathlib import Path
from os import listdir

for path in Path('.').rglob('*.efi'):
    try:
        files = listdir(path.parent.absolute())
        if(path.stem + ".depex" not in files):
            with open(str(path.parent.absolute()) + "/" + path.stem + ".inf","r") as f:
                alr = f.readlines()
            for line in alr:
                if("FILE_GUID" in line):
                    guid = line.split("=")[1].strip()
                if("BASE_NAME" in line):
                    ui = line.split("=")[1].strip()
            print("FILE DRIVER = " + guid + " {")
            print("    SECTION PE32 = $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/" + str(path))
            print('    SECTION UI = "' + ui + '"')
            print("}\n")
            #print(str(path) + " thereisntdepex")
    except Exception as e:
        print(e)
    