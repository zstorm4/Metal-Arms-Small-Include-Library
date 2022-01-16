

native heapspace();

native funcidx(const name[]);

native numargs();
native getarg(arg, index=0);
native setarg(arg, index=0, value);

native tolower(c);
native toupper(c);
native swapchars(c);

native random(max);

native min(value1, value2);
native max(value1, value2);
native clamp(value, min=cellmin, max=cellmax);

native getproperty();
native setproperty();
native deleteproperty();
native existproperty();

