 /*
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

static void utc_tizen_icu_api_ucnv_getAlias_func_01(void);
static void utc_tizen_icu_api_ucnv_getAlias_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_ucnv_getAlias_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_ucnv_getAlias_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucnv_getAlias start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucnv_getAlias ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_ucnv_getAlias()
 */
static void utc_tizen_icu_api_ucnv_getAlias_func_01(void)
{
	UErrorCode status = U_ZERO_ERROR;
	const char *result = NULL;
	const char *name = NULL;
	int32_t ncnv_cnt;

	ncnv_cnt = ucnv_countAvailable();

	if(ncnv_cnt > 0) {
		name = ucnv_getAvailableName(0);
		result = ucnv_getAlias(name, 0, &status);
		if ((U_SUCCESS(status)) && (NULL != result)) {
			tet_infoline("utc_tizen_icu_api_ucnv_getAlias test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline("utc_tizen_icu_api_ucnv_getAlias test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucnv_getAlias test FAIL!");
		tet_printf("ucnv available count is 0\n");
		tet_result(TET_FAIL);
	}
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_ucnv_getAlias()
 * sending converter as null will return error
 */
static void utc_tizen_icu_api_ucnv_getAlias_func_02(void)
{
	UErrorCode status = U_ZERO_ERROR;
	const char *result;

	result = ucnv_getAlias("UTF-7", 2, &status);
	if ((U_FAILURE(status)) || (NULL == result)) {
		tet_infoline("utc_tizen_icu_api_ucnv_getAlias test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_ucnv_getAlias test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	return;

}
