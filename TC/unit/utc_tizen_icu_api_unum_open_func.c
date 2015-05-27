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

static void utc_tizen_icu_api_unum_open_func_01(void);
static void utc_tizen_icu_api_unum_open_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_unum_open_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_unum_open_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_unum_open start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_unum_open ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_unum_open()
 */
static void utc_tizen_icu_api_unum_open_func_01(void)
{

	int32_t style[] =
	    { UNUM_DECIMAL, UNUM_CURRENCY, UNUM_PERCENT, UNUM_SCIENTIFIC,
		UNUM_SPELLOUT, UNUM_PATTERN_DECIMAL,
		UNUM_PATTERN_RULEBASED, UNUM_DEFAULT
	};
	UErrorCode status = U_ZERO_ERROR;
	UNumberFormat *num_fmt = NULL;
	int i;

	for (i = 0; i < 8; i++) {	/*If UNUM_PATTERN_DECIMAL or UNUM_PATTERN_RULEBASED is passed then 
					   the number format is opened using the given pattern */
		status = U_ZERO_ERROR;
		if ((style[i] == UNUM_PATTERN_DECIMAL)
		    || (style[i] == UNUM_PATTERN_RULEBASED)) {

			num_fmt =
			    unum_open(style[i], (const UChar *)"#,##,###", -1,
				      NULL, NULL, &status);
		} else {
			num_fmt =
			    unum_open(style[i], NULL, -1, NULL, NULL, &status);
		}
		if (U_SUCCESS(status) && (NULL != num_fmt)) {
			tet_infoline("utc_tizen_icu_api_unum_open test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline("utc_tizen_icu_api_unum_open test FAIL!");
			tet_printf("Error code %s", u_errorName(status));
			tet_result(TET_FAIL);
		}
		unum_close(num_fmt);
	}

	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_unum_open()
 * sent null for pattern in UNUM_PATTERN_DECIMAL & UNUM_PATTERN_RULEBASED
 */
static void utc_tizen_icu_api_unum_open_func_02(void)
{
	UErrorCode status = U_ZERO_ERROR;
	UNumberFormat *num_fmt = NULL;

	num_fmt =
	    unum_open(-1, NULL, -1, NULL, NULL, &status);

	if (U_FAILURE(status) && (NULL == num_fmt)) {
		tet_infoline("utc_tizen_icu_api_unum_open test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_unum_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	unum_close(num_fmt);

	return;

}
