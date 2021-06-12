all:
	@ echo "Compiling..."
	@ cargo build --target FOMOSv1-Yellow.json
	@ novus_boot target/FOMOSv1-Yellow/debug/FOMOSv1-Yellow.efi aarch64
	@ cp -r target/FOMOSv1-Yellow/debug/FOMOSv1-Yellow.fat FOMOSv1-Yellow
	@ echo "Created image at:"
	@ echo "/FOMOSv1-Yellow"

clean:
	@ cargo clean
	@ rm -rf FOMOSv1-Yellow

install:
	@ echo "Installing Novus Boot above the project directory..."
	@ cd ../ && git clone https://github.com/new-kernel/novus-boot/
	@ cd ../novus-boot/ && sh build.sh
