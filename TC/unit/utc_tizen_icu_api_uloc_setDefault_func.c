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

static void utc_tizen_icu_api_uloc_setDefault_func_01(void);
static void utc_tizen_icu_api_uloc_setDefault_func_02(void);
static void utc_tizen_icu_api_uloc_setDefault_func_03(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_uloc_setDefault_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_uloc_setDefault_func_02, NEGATIVE_TC_IDX},
	{utc_tizen_icu_api_uloc_setDefault_func_03, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_uloc_setDefault start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_uloc_setDefault ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_uloc_setDefault()
 */
static void utc_tizen_icu_api_uloc_setDefault_func_01(void)
{
	UErrorCode status = U_ZERO_ERROR;
	const char *locale = uloc_getDefault();

	uloc_setDefault(locale, &status);

	if (U_SUCCESS(status)) {
		tet_infoline("utc_tizen_icu_api_uloc_setDefault test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_uloc_setDefault test FAIL!");
		tet_printf("Error is %d", status);
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_uloc_setDefault()
 * to check if null send as a locale id it should set default locale id
 */
static void utc_tizen_icu_api_uloc_setDefault_func_02(void)
{
	UErrorCode status = U_ZERO_ERROR;
	const char *def_locale_before = uloc_getDefault();
	const char *def_locale_after;

	uloc_setDefault(NULL, &status);
	// If null send to the locale id it will set the default locale
	def_locale_after = uloc_getDefault();

	//checking old and new locale id is same
	if (!strcmp(def_locale_before, def_locale_after)) {
		tet_infoline("utc_tizen_icu_api_uloc_setDefault test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_uloc_setDefault test FAIL!");
		tet_printf("Error is %d", status);
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_uloc_setDefault()
 * to check if error code is greater than zero it should return the error code
 */
static void utc_tizen_icu_api_uloc_setDefault_func_03(void)
{
	UErrorCode status = U_ILLEGAL_ARGUMENT_ERROR;

	uloc_setDefault(uloc_getDefault(), &status);

	// the status value is more than 0 it will simply return 
	if (U_ILLEGAL_ARGUMENT_ERROR == status) {
		tet_infoline("utc_tizen_icu_api_uloc_setDefault test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_uloc_setDefault test FAIL!");
		tet_printf("Error is %d", status);
		tet_result(TET_FAIL);
	}
	return;
}
