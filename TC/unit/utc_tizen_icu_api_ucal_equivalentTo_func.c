 /*
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

static void utc_tizen_icu_api_ucal_equivalentTo_func_01(void);
static void utc_tizen_icu_api_ucal_equivalentTo_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_ucal_equivalentTo_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_ucal_equivalentTo_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucal_equivalentTo start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucal_equivalentTo ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_ucal_equivalentTo()
 */
static void utc_tizen_icu_api_ucal_equivalentTo_func_01(void)
{
	UCalendar *cal1 = NULL;
	UCalendar *cal2 = NULL;
	UBool result;
	UErrorCode status = U_ZERO_ERROR;
	int32_t type = UCAL_DEFAULT;

	cal1 = ucal_open(NULL, -1, NULL, type, &status);
	if (U_SUCCESS(status) && (NULL != cal1)) {
		cal2 = cal1;
		result = ucal_equivalentTo(cal1, cal2);
		if (result) {
			tet_infoline
			    ("utc_tizen_icu_api_ucal_equivalentTo test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucal_equivalentTo test FAIL!");
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucal_open test FAIL!");
		tet_printf("Error code %s", u_errorName(status));
		tet_result(TET_FAIL);
	}
	ucal_close(cal1);
	return;

}

/**
 * @brief Negative test case of utc_tizen_icu_api_ucal_equivalentTo()
 * camparing two calendar
 */
static void utc_tizen_icu_api_ucal_equivalentTo_func_02(void)
{
	UCalendar *cal1 = NULL;
	UCalendar *cal2 = NULL;
	UBool result;
	UErrorCode status = U_ZERO_ERROR;
	int32_t type = UCAL_DEFAULT;

	cal1 = ucal_open(NULL, -1, NULL, type, &status);
	cal2 = ucal_open(NULL, -1, NULL, UCAL_GREGORIAN, &status);

	if (U_SUCCESS(status)) {
		result = ucal_equivalentTo(cal1, cal2);
		if (result == TRUE) {
			tet_infoline
			    ("utc_tizen_icu_api_ucal_equivalentTo test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucal_equivalentTo test FAIL!");
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucal_open test FAIL!");
		tet_printf("Error code %s", u_errorName(status));
		tet_result(TET_FAIL);
	}
	ucal_close(cal1);
	return;

}
