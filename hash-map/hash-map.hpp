unsigned long djb2(unsigned char *str);

unsigned long h(unsigned long k);

unsigned long h2(unsigned long k, unsigned long i);

unsigned long rh(unsigned long k, unsigned long i);

unsigned long search(unsigned long key, long table[6250], unsigned long* chain);

unsigned long insert(unsigned long key, long table[6250], unsigned long* chain);

unsigned long remove(unsigned long key, long table[6250], unsigned long* chain);
