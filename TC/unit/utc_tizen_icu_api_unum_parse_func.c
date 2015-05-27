/*
 *  tizen-icu-api
 *
 * Copyright (c) 2000 - 2012 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Hakjoo Ko <hakjoo.ko@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <tet_api.h>
#include <unicode/utypes.h>
#include <unicode/uloc.h>
#include <unicode/ucal.h>
#include <unicode/udat.h>
#include <unicode/unum.h>
#include <unicode/ucnv.h>
#include <unicode/ustring.h>
#include <unistd.h>
#include<unicode/utmscale.h>

static void startup(void);
static void cleanup(void);

void (*tet_startup) (void) = startup;
void (*tet_cleanup) (void) = cleanup;

static void utc_tizen_icu_api_unum_parse_func_01(void);
static void utc_tizen_icu_api_unum_parse_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_unum_parse_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_unum_parse_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_unum_parse start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_unum_parse ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_unum_parse()
 */
static void utc_tizen_icu_api_unum_parse_func_01(void)
{
	UErrorCode status = U_ZERO_ERROR;
	int32_t num;
	UNumberFormat *num_fmt = NULL;
	const char *cs  = "1234";
	const int text_len = 4;
	UChar text[4];
	int32_t parse = 1;

	u_charsToUChars(cs, text, text_len);
	num_fmt = unum_open(UNUM_DEFAULT, NULL, -1, NULL, NULL, &status);
	if (U_SUCCESS(status) && (NULL != num_fmt)) {
		num = unum_parse(num_fmt, text, text_len, &parse, &status);
		if (U_SUCCESS(status) && num == 234) {
			tet_infoline("utc_tizen_icu_api_unum_parse test PASS!");
			tet_printf("The parsed number %d\n", num);
			tet_result(TET_PASS);
		} else {
			tet_infoline("utc_tizen_icu_api_unum_parse test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_unum_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	unum_close(num_fmt);
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_unum_parse()
 * Passing input text as null will return buffer overflow error
 */
static void utc_tizen_icu_api_unum_parse_func_02(void)
{
	UErrorCode status = U_ZERO_ERROR;
	int32_t num;
	UNumberFormat *num_fmt = NULL;
	const char *cs  = "1234";
	const int text_len = 4;
	UChar text[4];
	int32_t parse = 1;

	u_charsToUChars(cs, text, text_len);
	num_fmt = unum_open(UNUM_DEFAULT, NULL, -1, NULL, NULL, &status);
	if (U_SUCCESS(status) && (NULL != num_fmt)) {
		status = U_ILLEGAL_ARGUMENT_ERROR;
		num = unum_parse(num_fmt, text, text_len, &parse, &status);
		if (U_FAILURE(status) || num != 1234) {
			tet_infoline("utc_tizen_icu_api_unum_parse test PASS!");
			tet_printf("The parsed number %d\n", num);
			tet_result(TET_PASS);
		} else {
			tet_infoline("utc_tizen_icu_api_unum_parse test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_unum_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	unum_close(num_fmt);
	return;
}
