Name:      icu
Version:   4.8.1.1
Release:   1
Summary:   International Components for Unicode
Group:     Development/Tools
License:   ICU
URL:       http://www.icu-project.org/
Source0:   icu4c-4_8_1_1-src.tgz
Source1001: 	icu.manifest
BuildRequires: doxygen
BuildRequires: autoconf

%description
Tools and utilities for developing with icu.

%package -n lib%{name}
Summary: International Components for Unicode - libraries
Group:   System/i18n

%description -n lib%{name}
The International Components for Unicode (ICU) libraries provide
robust and full-featured Unicode services on a wide variety of
platforms. ICU supports the most current version of the Unicode
standard, and they provide support for supplementary Unicode
characters (needed for GB 18030 repertoire support).
As computing environments become more heterogeneous, software
portability becomes more important. ICU lets you produce the same
results across all the various platforms you support, without
sacrificing performance. It offers great flexibility to extend and
customize the supplied services.

%package  -n lib%{name}-devel
Summary:  Development files for International Components for Unicode
Group:    Development/Libraries
Requires: lib%{name} = %{version}-%{release}
Requires: pkgconfig

%description -n lib%{name}-devel
Includes and definitions for developing with icu.

%prep
%setup -q -n %{name}
cp %{SOURCE1001} .

%build
cd source
%configure ./runConfigureICU Linux --disable-renaming --prefix=%{_prefix}
make

%install
cd source
%make_install

# bugs of rpmdeps
chmod +x %{buildroot}/%{_libdir}/lib*.so.*

%remove_docs


%post -n lib%{name} -p /sbin/ldconfig

%postun -n lib%{name} -p /sbin/ldconfig

%files
%manifest %{name}.manifest

%files -n lib%{name}
%manifest %{name}.manifest
%{_libdir}/*.so*
%{_bindir}/derb
%{_bindir}/genbrk
%{_bindir}/gencfu
%{_bindir}/gencnval
%{_bindir}/genctd
%{_bindir}/genrb
%{_bindir}/makeconv
%{_bindir}/pkgdata
%{_bindir}/uconv
%{_bindir}/icuinfo
%{_bindir}/icu-config
%{_sbindir}/*
%dir %{_datadir}/icu/4.8.1.1
%{_datadir}/icu/4.8.1.1/config/mh-linux
%{_datadir}/icu/4.8.1.1/install-sh
%{_datadir}/icu/4.8.1.1/license.html
%{_datadir}/icu/4.8.1.1/mkinstalldirs

%files -n lib%{name}-devel
%manifest %{name}.manifest
%{_includedir}/layout
%{_includedir}/unicode
%{_libdir}/*.so
%{_libdir}/pkgconfig/icu-*.pc
%{_libdir}/%{name}
