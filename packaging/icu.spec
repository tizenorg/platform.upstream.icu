Name:      icu
Version:   51
Release:   1
Summary:   International Components for Unicode
Group:     Development/Tools
License:   ICU
URL:       http://www.icu-project.org/
Source0:   %{name}-%{version}.tar.gz
Source1:   %{name}.manifest
BuildRequires: doxygen, autoconf

%description
Tools and utilities for developing with icu.

%package -n lib%{name}
Summary: International Components for Unicode - libraries
Group:   System/Libraries

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
%setup -q
cp %{SOURCE1} lib%{name}.manifest

%build
%reconfigure ./runConfigureICU Linux --disable-renaming --prefix=%{_prefix}

make # %{?_smp_mflags} # -j(X>1) may "break" man pages as of 3.2, b.f.u #2357

%install
make DESTDIR=%{buildroot} install

# bugs of rpmdeps
chmod +x %{buildroot}/%{_libdir}/lib*.so.*

mkdir -p %{buildroot}/usr/share/license
cp -f LICENSE %{buildroot}/usr/share/license/lib%{name}

%remove_docs

%clean
rm -rf $RPM_BUILD_ROOT

%post -n lib%{name} -p /sbin/ldconfig

%postun -n lib%{name} -p /sbin/ldconfig

%files

%files -n lib%{name}
%manifest lib%{name}.manifest
%{_libdir}/*.so*
%{_bindir}/derb
%{_bindir}/genbrk
%{_bindir}/gencfu
%{_bindir}/gencnval
#%{_bindir}/genctd
%{_bindir}/gendict
%{_bindir}/genrb
%{_bindir}/makeconv
%{_bindir}/pkgdata
%{_bindir}/uconv
%{_bindir}/icuinfo
%{_bindir}/icu-config
%{_sbindir}/*
%dir /usr/share/icu/51.1
/usr/share/icu/51.1/config/mh-linux
/usr/share/icu/51.1/install-sh
/usr/share/icu/51.1/license.html
/usr/share/icu/51.1/mkinstalldirs
/usr/share/license/lib%{name}

%files -n lib%{name}-devel
%{_includedir}/layout
%{_includedir}/unicode
%{_libdir}/*.so
%{_libdir}/pkgconfig/icu-*.pc
%{_libdir}/%{name}
#/usr/share/license/lib%{name}
