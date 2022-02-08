define uninstall
	@echo -n "removing builded structures.. "
	@rm -rf "/etc/themis" "/usr/share/themis" "/usr/local/lib/bash/5.17/themis"
	@echo "ok"
endef

install:
	@bash ./install.sh

uninstall:
	$(uninstall)

reinstall:
	$(uninstall)
	@bash ./install.sh