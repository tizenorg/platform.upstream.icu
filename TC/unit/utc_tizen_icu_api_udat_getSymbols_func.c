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

static void utc_tizen_icu_api_udat_getSymbols_func_01(void);
static void utc_tizen_icu_api_udat_getSymbols_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_udat_getSymbols_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_udat_getSymbols_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_udat_getSymbols start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_udat_getSymbols ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_udat_getSymbols()
 */
static void utc_tizen_icu_api_udat_getSymbols_func_01(void)
{
	UDateFormat *date_fmt = NULL;
	int32_t type[] =
	    { UDAT_ERAS, UDAT_MONTHS, UDAT_SHORT_MONTHS, UDAT_WEEKDAYS,
		UDAT_SHORT_WEEKDAYS, UDAT_AM_PMS, UDAT_LOCALIZED_CHARS
	};
	UChar result[50] = { 0, };
	UErrorCode status = U_ZERO_ERROR;
	int32_t ret = 0;
	int32_t i;

	date_fmt =
	    udat_open(UDAT_NONE, UDAT_SHORT, NULL, NULL, -1, NULL, -1, &status);

	if (U_SUCCESS(status) ) {
		for (i = 0; i < 7; i++) {
			ret =
			    udat_getSymbols(date_fmt, type[i], 5, result, 50,
					    &status);
			if ((U_SUCCESS(status))) {
				tet_infoline
				    ("utc_tizen_icu_api_udat_getSymbols test PASS!");
				tet_printf("Date Symbol %s\n", result);
				tet_result(TET_PASS);
			} else {
				tet_infoline
				    ("utc_tizen_icu_api_udat_getSymbols test FAIL!");
				tet_printf("Error code %s\n", u_errorName(status));
				tet_result(TET_FAIL);
			}
		}
	} else {
		tet_infoline("utc_tizen_icu_api_udat_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	udat_close(date_fmt);

	return;
}


/**
 * @brief Negative test case of utc_tizen_icu_api_udat_getSymbols()
 * passing the NULL as a result will through error.
 */
static void utc_tizen_icu_api_udat_getSymbols_func_02(void)
{
	UDateFormat *date_fmt = NULL;
	UErrorCode status = U_ZERO_ERROR;
	int32_t ret;

	date_fmt =
	    udat_open(UDAT_NONE, UDAT_SHORT, NULL, NULL, -1, NULL, -1, &status);

	if (U_SUCCESS(status) && (NULL != date_fmt)) {

		ret =
		    udat_getSymbols(date_fmt, UDAT_MONTHS, 1, NULL, -1,
				    &status);
		if (U_FAILURE(status)) {
			tet_infoline
			    ("utc_tizen_icu_api_udat_getSymbols test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_udat_getSymbols test FAIL!");
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_udat_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	udat_close(date_fmt);

}
