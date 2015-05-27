/*
 *  tizen-icu-api
 *
 * Copyright (c) 2000 - 2012 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Jayoun Lee <airjany@samsung.com>
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

static void utc_tizen_icu_api_uloc_getVariant_func_01(void);
static void utc_tizen_icu_api_uloc_getVariant_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_uloc_getVariant_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_uloc_getVariant_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_uloc_getVariant start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_uloc_getVariant ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_uloc_getVariant()
 */
static void utc_tizen_icu_api_uloc_getVariant_func_01(void)
{
	const char *locale_id = uloc_getDefault();
	char variant[20] = {0,};
	int32_t variant_capacity = 20;
	UErrorCode err = U_ZERO_ERROR;
	int32_t result;

	result = uloc_getVariant(locale_id, variant, variant_capacity, &err);

	if (U_SUCCESS(err)) {
		tet_infoline("utc_tizen_icu_api_uloc_getVariant test PASS!");
		tet_printf("variant for this %s locale %s\n", locale_id,
			   variant);
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_uloc_getVariant test FAIL!");
		tet_printf("Error is %d\n", err);
		tet_result(TET_FAIL);
	}
	return;
}


/**
 * @brief Negative test case of utc_tizen_icu_api_uloc_getVariant()
 * if err code is null will return error
 */
static void utc_tizen_icu_api_uloc_getVariant_func_02(void)
{
	const char *locale_id = uloc_getDefault();
	char variant[20] = { 0, };
	int32_t variant_capacity = 20;
	int32_t result;

	result = uloc_getVariant(locale_id, variant, variant_capacity, NULL);

	if (0 == result) {
		tet_infoline("utc_tizen_icu_api_uloc_getVariant test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_uloc_getVariant test FAIL!");
		tet_result(TET_FAIL);
	}
	return;
}
