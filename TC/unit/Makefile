CC ?= gcc

TARGETS = utc_tizen_icu_api_uloc_getDefault_func \
	utc_tizen_icu_api_uloc_setDefault_func \
	utc_tizen_icu_api_uloc_getAvailable_func \
	utc_tizen_icu_api_uloc_getCountry_func \
	utc_tizen_icu_api_uloc_getDisplayCountry_func \
	utc_tizen_icu_api_uloc_getDisplayLanguage_func \
	utc_tizen_icu_api_uloc_getDisplayName_func \
	utc_tizen_icu_api_uloc_getDisplayVariant_func \
	utc_tizen_icu_api_uloc_getISO3Country_func \
	utc_tizen_icu_api_uloc_getISO3Language_func \
	utc_tizen_icu_api_uloc_getISOCountries_func \
	utc_tizen_icu_api_uloc_getISOLanguages_func \
	utc_tizen_icu_api_uloc_getLanguage_func \
	utc_tizen_icu_api_uloc_getVariant_func \
        utc_tizen_icu_api_ucal_clearField_func \
        utc_tizen_icu_api_ucal_clear_func \
        utc_tizen_icu_api_ucal_close_func \
        utc_tizen_icu_api_ucal_equivalentTo_func \
        utc_tizen_icu_api_ucal_getAvailable_func \
        utc_tizen_icu_api_ucal_getDefaultTimeZone_func \
        utc_tizen_icu_api_ucal_getDSTSavings_func \
        utc_tizen_icu_api_ucal_getLimit_func \
        utc_tizen_icu_api_ucal_getMillis_func \
        utc_tizen_icu_api_ucal_getTimeZoneDisplayName_func \
        utc_tizen_icu_api_ucal_inDaylightTime_func \
        utc_tizen_icu_api_ucal_isSet_func \
        utc_tizen_icu_api_ucal_open_func \
        utc_tizen_icu_api_ucal_roll_func \
        utc_tizen_icu_api_ucal_setDate_func \
        utc_tizen_icu_api_ucal_setDateTime_func \
        utc_tizen_icu_api_ucal_setDefaultTimeZone_func \
        utc_tizen_icu_api_ucal_set_func \
        utc_tizen_icu_api_ucal_setGregorianChange_func \
        utc_tizen_icu_api_ucal_setMillis_func \
        utc_tizen_icu_api_ucal_setTimeZone_func \
        utc_tizen_icu_api_ucnv_close_func \
        utc_tizen_icu_api_ucnv_compareNames_func \
        utc_tizen_icu_api_ucnv_convertEx_func \
        utc_tizen_icu_api_ucnv_countAvailable_func \
        utc_tizen_icu_api_ucnv_flushCache_func \
        utc_tizen_icu_api_u_errorName_func \
        utc_tizen_icu_api_u_strFromWCS_func \
        utc_tizen_icu_api_u_strToWCS_func \
        utc_tizen_icu_api_udat_close_func \
        utc_tizen_icu_api_udat_format_func \
        utc_tizen_icu_api_udat_getCalendar_func \
        utc_tizen_icu_api_udat_getSymbols_func \
        utc_tizen_icu_api_udat_isLenient_func \
        utc_tizen_icu_api_udat_open_func \
        utc_tizen_icu_api_udat_setLenient_func \
        utc_tizen_icu_api_udat_setSymbols_func \
        utc_tizen_icu_api_udat_toPatternRelativeDate_func \
        utc_tizen_icu_api_unum_close_func \
        utc_tizen_icu_api_unum_formatDecimal_func \
        utc_tizen_icu_api_unum_formatDouble_func \
        utc_tizen_icu_api_unum_format_func \
        utc_tizen_icu_api_unum_formatInt64_func \
        utc_tizen_icu_api_unum_open_func \
        utc_tizen_icu_api_unum_parseDecimal_func \
        utc_tizen_icu_api_unum_parseDouble_func \
        utc_tizen_icu_api_unum_parse_func \
        utc_tizen_icu_api_unum_parseInt64_func \
        utc_tizen_icu_api_ucnv_fromUChars_func \
        utc_tizen_icu_api_ucnv_fromUnicode_func \
        utc_tizen_icu_api_ucnv_getAlias_func \
        utc_tizen_icu_api_ucnv_getAvailableName_func \
        utc_tizen_icu_api_ucnv_getCanonicalName_func \
        utc_tizen_icu_api_ucnv_getDisplayName_func \
        utc_tizen_icu_api_ucnv_getMaxCharSize_func \
        utc_tizen_icu_api_ucnv_getMinCharSize_func \
        utc_tizen_icu_api_ucnv_getName_func \
        utc_tizen_icu_api_ucnv_open_func \
        utc_tizen_icu_api_ucnv_reset_func \
        utc_tizen_icu_api_ucnv_setFallback_func \
        utc_tizen_icu_api_ucnv_setFromUCallBack_func \
        utc_tizen_icu_api_ucnv_setToUCallBack_func \
        utc_tizen_icu_api_ucnv_toUChars_func \
        utc_tizen_icu_api_ucnv_toUnicode_func


PKGS= icu-i18n icu-io icu-le icu-lx icu-uc

LDFLAGS= `pkg-config --libs $(PKGS)`
LDFLAGS+= $(TET_ROOT)/lib/tet3/tcm_s.o
LDFLAGS+= -L$(TET_ROOT)/lib/tet3 -ltcm_s
LDFLAGS+= -L$(TET_ROOT)/lib/tet3 -lapi_s

CFLAGS= -I. `pkg-config --cflags $(PKGS)`
CFLAGS+= -I$(TET_ROOT)/inc/tet3
CFLAGS+= -Wall

all: $(TARGETS)

$(TARGETS): %: %.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGETS)
