MYSQL_LIB=$(shell mysql_config --cflags --libs)
MYSQL_PLUGINDIR=$(shell mysql_config --plugindir)

all: mysql

mysql: 
	gcc -Wall ${MYSQL_LIB} -fPIC -shared -o microsecnow.so microsecnow.c

install:
	install -m 0644 microsecnow.so ${MYSQL_PLUGINDIR}
	@echo ""
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo ""
	@echo "please now in the mysql shell execute:" 
	@echo ""
	@echo "CREATE FUNCTION microsecnow RETURNS INTEGER SONAME 'microsecnow.so'"	
	@echo ""
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo ""

clean:
	rm -f *.so


