# Possible new GCs

## GC1
```
a = OBJ # gc push a
b = OBJ # gc push b
c = []  # gc push c
c.append(a) # gc pop a; gc.c push a
c.append(b) # gc pop b; gc.c push b
a # NameError!
b # NameError!
```

## GC2
```
a = {}          # a.rc = 1, weak
b = {}          # b.rc = 1, weak
a['b'] = b      # a becomes strong, a.rc = 1; b becomes weak, b.rc = 2
b['a'] = a      # a stays strong, b.rc = 2; b stays weak, a.rc = 1
# ---
deref(b)        # deref(b), b.rc = 1
deref(a)        # deref(a), a.rc = 0; deref(b), b.rc = 0; 
```