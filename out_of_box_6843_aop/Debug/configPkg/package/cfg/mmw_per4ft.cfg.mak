# invoke SourceDir generated makefile for mmw.per4ft
mmw.per4ft: .libraries,mmw.per4ft
.libraries,mmw.per4ft: package/cfg/mmw_per4ft.xdl
	$(MAKE) -f C:\Users\PETABREW001\workspace_v12\out_of_box_6843_aop/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\PETABREW001\workspace_v12\out_of_box_6843_aop/src/makefile.libs clean

