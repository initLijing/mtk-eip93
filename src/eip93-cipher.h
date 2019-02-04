// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2019
 *
 * Richard van Schagen <vschagen@cs.com>
 */

#ifndef _CIPHER_H_
#define _CIPHER_H_

struct mtk_cipher_ctx {
	struct mtk_context			base;
	struct mtk_device			*mtk;
	u8							key[AES_MAX_KEY_SIZE];
	u32							keylen;
	struct crypto_skcipher		*fallback;
	bool						aead;
	/* AEAD specific */
	u32							hash_alg;
	u32							state_sz;
	u32							ipad[SHA256_DIGEST_SIZE / sizeof(u32)];
	u32							opad[SHA256_DIGEST_SIZE / sizeof(u32)];
};

struct mtk_cipher_reqctx {
	unsigned long			flags;
	int						blksize;
	/* copy in case of mis-alignment */
	struct scatterlist		*sg_src;
	struct scatterlist		*sg_dst;
	/* AES-CTR in case of counter overflow */
	struct scatterlist		ctr_src[2];
	struct scatterlist		ctr_dst[2];
};

#endif /* _CIPHER_H_ */
