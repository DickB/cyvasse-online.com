AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = cyvasse-online

cyvasse_online_ecpp_sources = \
	webapp/404.ecpp \
	webapp/500.ecpp \
	webapp/index.ecpp \
	webapp/page.ecpp

BUILT_SOURCES = $(cyvasse_online_ecpp_sources:.ecpp=.cpp)

cyvasse_online_SOURCES = \
	webapp/cpp_src/main.cpp \
	$(cyvasse_online_ecpp_sources)

nodist_cyvasse_online_SOURCES = $(cyvasse_online_ecpp_sources:.ecpp=.cpp)

cyvasse_online_CXXFLAGS = \
	-std=c++11

cyvasse_online_LDADD = \
	-lcxxtools \
	-ltntnet

CLEANFILES = $(cyvasse_online_ecpp_sources:.ecpp=.cpp) $(cyvasse_online_ecpp_sources:.ecpp=.deps)

ECPPCFLAGS = -I $(top_srcdir)/webapp/include

webapp/%.cpp: webapp/%.ecpp
	$(AM_V_GEN)$(ECPPC) $(ECPPCFLAGS) -n "$*" -m text/html -o $@ $<
%.deps: %.ecpp
	$(AM_V_GEN)$(ECPPC) -M $(ECPPCFLAGS) $< | $(SED) '1s/\(.*\).cpp:/\1.cpp \1.deps:/' > $@

-include $(cyvasse_online_ecpp_sources:.ecpp=.deps)
