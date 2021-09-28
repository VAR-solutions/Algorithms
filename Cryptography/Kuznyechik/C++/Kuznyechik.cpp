#include "kuznechik.h"
#include <cstring>

constexpr unsigned char Kuznechik::Pi[256];
constexpr unsigned char Kuznechik::revPi[256];
constexpr unsigned char Kuznechik::koef[16];

uint8_t *Kuznechik::encrypt(const uint8_t *key, const uint8_t *plaintext)
{
    expandKey(key, key + BLOCK_SIZE);
    uint8_t* res = new uint8_t[BLOCK_SIZE];
    _encrypt(plaintext, res);
    return res;
}

uint8_t *Kuznechik::decrypt(const uint8_t *key, const uint8_t *ciphertext)
{
    expandKey(key, key + BLOCK_SIZE);
    uint8_t* res = new uint8_t[BLOCK_SIZE];
    _decrypt(ciphertext, res);
    return res;
}

void Kuznechik::_encrypt(const uint8_t *in, uint8_t *out)
{

    std::memcpy(out, in, BLOCK_SIZE);
    for (int i = 0; i < 9; ++i) {
        transfX(iterKey[i], out, out);
        transfS(out, out);
        transfL(out, out);
    }
    transfX(out, iterKey[9], out);
}

void Kuznechik::_decrypt(const uint8_t *in, uint8_t *out)
{
    std::memcpy(out, in, BLOCK_SIZE);
    transfX(out, iterKey[9], out);
    for (int i = 8; i >= 0; --i) {
        transfRevL(out, out);
        transfRevS(out, out);
        transfX(iterKey[i], out, out);
    }
}

void Kuznechik::transfX(const uint8_t *a, const uint8_t *b, uint8_t *c)
{
    for (int i = 0; i < BLOCK_SIZE; ++i) c[i] = a[i] ^ b[i];
}

void Kuznechik::transfS(const uint8_t *in, uint8_t* out)
{
    for (int i = 0; i < BLOCK_SIZE; ++i) out[i] = Pi[in[i]];
}

void Kuznechik::transfRevS(const uint8_t *in, uint8_t *out)
{
    for (int i = 0; i < BLOCK_SIZE; ++i) out[i] = revPi[in[i]];
}

void Kuznechik::transfR(uint8_t *vector)
{
        uint8_t a15 = 0;
        uint8_t temp[16];
        for (int i = 15; i >= 0; i--)
        {
            temp[i - 1] = vector[i];
            a15 ^= gfMul(vector[i], koef[i]);
        }
        temp[15] = a15;
        memcpy(vector, temp, BLOCK_SIZE);
}

void Kuznechik::transfRevR(uint8_t *vector)
{

        uint8_t a0;
        a0 = vector[15];
        uint8_t temp[16];
        for (int i = 0; i < 16; i++)
        {
            temp[i] = vector[i - 1];
            a0 ^= gfMul(temp[i], koef[i]);
        }
        temp[0] = a0;
        memcpy(vector, temp, BLOCK_SIZE);
}

void Kuznechik::transfL(const uint8_t *in, uint8_t *out)
{
    std::memcpy(out, in, BLOCK_SIZE);
    for (int i = 0; i < 16; ++i) transfR(out);
}

void Kuznechik::transfRevL(const uint8_t *in, uint8_t *out)
{
    std::memcpy(out, in, BLOCK_SIZE);
    for (int i = 0; i < 16; ++i) transfRevR(out);
}

void Kuznechik::F(const uint8_t *in1, const uint8_t *in2, uint8_t *out1, uint8_t *out2, const uint8_t *iterConst)
{
    uint8_t internal[BLOCK_SIZE];
    std::memcpy(out2, in1, BLOCK_SIZE);
    transfX(in1, iterConst, internal);
    transfS(internal, internal);
    transfL(internal, internal);
    transfX(internal, in2, out1);
}

void Kuznechik::expandKey(const uint8_t *k1, const uint8_t *k2)
{
    uint8_t it1[64];
    uint8_t it2[64];
    uint8_t it3[64];
    uint8_t it4[64];
    getConsts();
    memcpy(iterKey[0], k1, 64);
    memcpy(iterKey[1], k2, 64);
    memcpy(it1, k1, 64);
    memcpy(it2, k2, 64);
    for (int i = 0; i < 4; i++)
        {
            F(it1, it2, it3, it4, iterConsts[0 + 8 * i]);
            F(it3, it4, it1, it2, iterConsts[1 + 8 * i]);
            F(it1, it2, it3, it4, iterConsts[2 + 8 * i]);
            F(it3, it4, it1, it2, iterConsts[3 + 8 * i]);
            F(it1, it2, it3, it4, iterConsts[4 + 8 * i]);
            F(it3, it4, it1, it2, iterConsts[5 + 8 * i]);
            F(it1, it2, it3, it4, iterConsts[6 + 8 * i]);
            F(it3, it4, it1, it2, iterConsts[7 + 8 * i]);
            memcpy(iterKey[2 * i + 2], it1, 64);
            memcpy(iterKey[2 * i + 3], it2, 64);
        }
}

void Kuznechik::getConsts()
{
    uint8_t iter_num[32][16];
    for (int i = 0; i < 32; i++)
    {
        std::memset(iter_num[i], 0, BLOCK_SIZE);
        iter_num[i][0] = i+1;
    }
    for (int i = 0; i < 32; i++)
         transfL(iter_num[i], iterConsts[i]);
}

uint8_t Kuznechik::gfMul(uint8_t a, uint8_t b)
{
    uint8_t res = 0;
    uint8_t h = 0;
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        if (b & 1) res ^= a;
        h = a & 0b10000000;
        a <<= 1;
        if (h) a ^= 0b11000011;
        b >>= 1;
    }
    return res;
}
