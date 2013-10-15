Name:      icu
Version:   4.8.1.1
Release:   1
Summary:   International Components for Unicode
Group:      System/Libraries
License:   ICU
URL:       http://www.icu-project.org/
Source0:   icu4c-4_8_1_1-src.tgz
Source1001: 	icu.manifest
BuildRequires: doxygen
BuildRequires: autoconf

%description
Tools and utilities for developing with icu.

%package -n libicu
Summary: International Components for Unicode - libraries

%description -n libicu
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

%package  -n libicu-devel
Summary:  Development files for International Components for Unicode
Requires: libicu = %{version}-%{release}
Requires: pkgconfig

%description -n libicu-devel
Includes and definitions for developing with icu.

%prep
%setup -q -n %{name}
cp %{SOURCE1001} .

%build
cd source
%configure --disable-static \
            --disable-renaming \
            --enable-shared \
            --disable-samples
make %{?_smp_mflags}

%install
cd source
%make_install

cd -
mkdir -p %{buildroot}/usr/share/license
cp LICENSE %{buildroot}/usr/share/license/%{name}
cp LICENSE %{buildroot}/usr/share/license/lib%{name}
cp LICENSE %{buildroot}/usr/share/license/lib%{name}-devel

# bugs of rpmdeps
chmod +x %{buildroot}/%{_libdir}/lib*.so.*

%remove_docs


%post -n libicu -p /sbin/ldconfig

%postun -n libicu -p /sbin/ldconfig

%files
%manifest %{name}.manifest
/usr/share/license/%{name}

%files -n libicu
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
%dir %{_datadir}/icu/%{version}
%{_datadir}/icu/%{version}/config/mh-linux
%{_datadir}/icu/%{version}/install-sh
%{_datadir}/icu/%{version}/license.html
%{_datadir}/icu/%{version}/mkinstalldirs
/usr/share/license/lib%{name}

%files -n libicu-devel
%manifest %{name}.manifest

%{_includedir}/layout
%{_includedir}/unicode
%{_libdir}/*.so
%{_libdir}/pkgconfig/icu-*.pc
%{_libdir}/%{name}
/usr/share/license/lib%{name}-devel
