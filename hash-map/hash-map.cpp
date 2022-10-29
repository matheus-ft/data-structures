#include <iostream>
#include "hash-map.hpp"

unsigned long djb2(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) ^ c; // hash * 33 XOR c

    return hash;
}

unsigned long h(unsigned long k) {
    return k % 6250;
}

unsigned long h2(unsigned long k, unsigned long i) {
    return 1 + (k % 6249);
}

unsigned long rh(unsigned long k, unsigned long i) {
    unsigned long H = h(k) + (i * h2(k, i));
    return H % 6250;
}

unsigned long search(unsigned long key, long table[6250], unsigned long* chain) {
    unsigned long k = chain[0];
    unsigned long count = chain[1];

    if (key >= 6250)
        return -3;  // a posicao gerada pela funcao de hashing excede o tamanho da tabela

    else if (table[key] == k)
        return key;

    else if (table[key] == -1)  // -1 significa que a posicao na tabela esta vazia
        return -1;

    else if (table[key] == -2  || (table[key] != k && table[key] != 1)) {
        // se havia um registro que foi removido ou se a posicao <key> está ocupada mas nao é pela <chain[0]> :
        ++count;
        unsigned long newchain[2] = {k, count};
        return search(rh(chain[0], chain[1]),
                      table,
                      newchain
                      );
    }

    else  // algo deu errado
        return -4;
}

unsigned long insert(unsigned long key, long table[6250], unsigned long* chain) {
    unsigned long k = chain[0];
    unsigned long count = chain[1];

    unsigned long state = search(key, table, chain);

    if (table[key] == -1) {  // table[key] == -1 || table[key] == -2
        table[key] = k;
        return 1;
    }

    else if (state == key) { // <state >= 0> equivale a <state == key>
        return 0;  // <chain[0]> ja esta na tabela
    }

    else if (table[key] != k || table[key] == -2) {  // table[key] != k
        count++;
        unsigned long newchain[2] = {k, count};
        return insert(rh(newchain[0], newchain[1]),
                      table,
                      newchain
                      );
    }

    else  // algo deu errado
        return -4;
}

unsigned long remove(unsigned long key, long table[6250], unsigned long* chain) {
    unsigned long k = chain[0];
    unsigned long count = chain[1];

    if (table[key] == k) {
        table[key] = -2;
        return 1;  // -2 significa que a posicao na tabela ja teve um registro, mas que foi removido
    }

    else if (table[key] == -1) {
        return 0;  // <chain[0]> nao esta na tabela
    }

    else if (table[key] == -2  || table[key] != k) {
        ++count;
        unsigned long newchain[2] = {k, count};
        return delete(rh(newchain[0], newchain[1]),
                      table,
                      newchain
                      );
    }

    else  // algo deu errado
        return -4;
}
