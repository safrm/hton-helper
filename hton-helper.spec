Name:       hton-helper
Summary:    Byte order helper and calculator
Version:    0.0.1
Release:    1
Group:      Development/Tools
License:    LGPL v2.1
URL:        http://safrm.net/projects/hton-helper
Vendor:     Miroslav Safr <miroslav.safr@gmail.com>
Source0:    %{name}-%{version}.tar.bz2
BuildRequires:  gcc

%description
Byte order helper and calculator

%prep
%setup -c -n ./%{name}-%{version}

%build
make %{?jobs:-j%jobs} all

%install
make install  -e DESTDIR=%{buildroot}

%clean
rm -fr 

%files
%defattr(-,root,root,-)
%{_bindir}/hton-helper
