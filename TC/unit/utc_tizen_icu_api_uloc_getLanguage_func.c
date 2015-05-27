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

static void utc_tizen_icu_api_uloc_getLangugae_func_01(void);
static void utc_tizen_icu_api_uloc_getLangugae_func_02(void);
static void utc_tizen_icu_api_uloc_getLangugae_func_03(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_uloc_getLangugae_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_uloc_getLangugae_func_02, NEGATIVE_TC_IDX},
	{utc_tizen_icu_api_uloc_getLangugae_func_03, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_uloc_getLangugae start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_uloc_getLangugae ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_uloc_getLangugae()
 */
static void utc_tizen_icu_api_uloc_getLangugae_func_01(void)
{
	const char *locale_id = uloc_getDefault();
	char language[20] = { 0, };
	int32_t language_capacity = 20;
	UErrorCode err = U_ZERO_ERROR;
	int32_t result;

	result = uloc_getLanguage(locale_id, language, language_capacity, &err);

	/*result = 0 failed to getLanguage result > languageCapacity mean
	   language truncated */
	if ((result != 0) && (U_SUCCESS(err))) {

		tet_infoline("utc_tizen_icu_api_uloc_getLangugae test PASS!");
		tet_printf("Langauage for the %s locale  %s", locale_id,
			   language);
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_uloc_getLangugae test FAIL!");
		tet_printf("Error is %d\n", err);
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_uloc_getLangugae()
 * if errcode is assigned to null function should return 0
 */
static void utc_tizen_icu_api_uloc_getLangugae_func_02(void)
{
	const char *locale_id = uloc_getDefault();
	char language[20] = {
		0,
	};
	int32_t language_capacity = 20;
	int32_t result;
	result = uloc_getLanguage(locale_id, language, language_capacity, NULL);
	/* function should return zero if errorcode is null */
	if (0 == result) {
		tet_infoline("utc_tizen_icu_api_uloc_getLangugae test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_uloc_getLangugae test FAIL!");
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_uloc_getLangugae()
 * if errcode is postive value it will return 0
 */
static void utc_tizen_icu_api_uloc_getLangugae_func_03(void)
{
	const char *locale_id = uloc_getDefault();
	UErrorCode err = 5;
	char language[20] = {0,};
	int32_t result;
	result = uloc_getLanguage(locale_id, language, 20, &err);
	/* function should return zero if the errorcode is not equal to zero */
	if (0 == result) {
		tet_infoline("utc_tizen_icu_api_uloc_getLangugae test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_uloc_getLangugae test FAIL!");
		tet_printf("Error is %d\n", err);
		tet_result(TET_FAIL);
	}
	return;
}
