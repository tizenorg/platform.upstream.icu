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

static void utc_tizen_icu_api_ucal_getLimit_func_01(void);
static void utc_tizen_icu_api_ucal_getLimit_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_ucal_getLimit_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_ucal_getLimit_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucal_getLimit start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucal_getLimit ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_ucal_getLimit()
 */
static void utc_tizen_icu_api_ucal_getLimit_func_01(void)
{
	UCalendar *cal = NULL;
	UErrorCode status = U_ZERO_ERROR;
	int32_t type = UCAL_DEFAULT;
	int32_t field[] = { UCAL_ERA, UCAL_YEAR, UCAL_MONTH, UCAL_WEEK_OF_YEAR,
		UCAL_WEEK_OF_MONTH, UCAL_DATE, UCAL_DAY_OF_YEAR,
		UCAL_DAY_OF_WEEK, UCAL_DAY_OF_WEEK_IN_MONTH,
		UCAL_AM_PM, UCAL_HOUR, UCAL_HOUR_OF_DAY,
		UCAL_MINUTE, UCAL_SECOND, UCAL_MILLISECOND,
		UCAL_ZONE_OFFSET, UCAL_DST_OFFSET
	};
	int32_t index = 0;
	int32_t limit_type[] =
	    { UCAL_MINIMUM, UCAL_MAXIMUM, UCAL_GREATEST_MINIMUM,
		UCAL_LEAST_MAXIMUM, UCAL_ACTUAL_MINIMUM, UCAL_ACTUAL_MAXIMUM
	};
	int32_t value = 1;
	int32_t result = 0;
	int32_t lp_cnt = 0;

	cal = ucal_open(NULL, -1, NULL, type, &status);
	if (U_SUCCESS(status) && (NULL != cal)) {
		for (index = 0; index < 17; index++) {
			ucal_set(cal, field[index], value);
			if (ucal_isSet(cal, field[index])) {
				for (lp_cnt = 0; lp_cnt < 6; lp_cnt++) {
					result =
					    ucal_getLimit(cal, field[index],
							  limit_type[lp_cnt],
							  &status);
					if (U_SUCCESS(status)) {
						tet_infoline
						    ("utc_tizen_icu_api_ucal_getLimit test PASS!");
						tet_result(TET_PASS);

					} else {
						tet_infoline
						    ("utc_tizen_icu_api_ucal_getLimit test FAIL!");
						tet_printf("Error code %s",
							   u_errorName(status));
						tet_result(TET_FAIL);
					}
				}

			} else {
				tet_infoline
				    ("utc_tizen_icu_api_ucal_open test FAIL!");
				tet_printf("Error code %s",
					   u_errorName(status));
				tet_result(TET_FAIL);
			}
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucal_open test FAIL!");
		tet_printf("Error code %s", u_errorName(status));
		tet_result(TET_FAIL);
	}

	ucal_close(cal);
	return;

}

/**
 * @brief Negative test case of utc_tizen_icu_api_ucal_getLimit()
 * if status is null will return error
 */
static void utc_tizen_icu_api_ucal_getLimit_func_02(void)
{
	UCalendar *cal = NULL;
	UErrorCode status = U_ZERO_ERROR;
	int32_t type = UCAL_DEFAULT;
	int32_t field = UCAL_ERA;
	int32_t limit_type = UCAL_GREATEST_MINIMUM;
	int32_t result = 0;

	cal = ucal_open(NULL, -1, NULL, type, &status);
	if (U_SUCCESS(status) && (NULL != cal)) {
		result = ucal_getLimit(cal, field, limit_type, NULL);
		if (result) {
			tet_infoline("utc_tizen_icu_api_ucal_getLimit test PASS!");
			tet_result(TET_PASS);

		} else {
			tet_infoline("utc_tizen_icu_api_ucal_getLimit test FAIL!");
			tet_printf("Error code %s", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucal_open test FAIL!");
		tet_printf("Error code %s", u_errorName(status));
		tet_result(TET_FAIL);
	}
	return;
}
