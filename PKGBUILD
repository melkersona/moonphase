# This is an example PKGBUILD file. Use this as a start to creating your own,
# and remove these comments. For more information, see 'man PKGBUILD'.
# NOTE: Please fill out the license field for your package! If it is unknown,
# then please put 'unknown'.

# Maintainer: Alva Melkerson <alva.melkerson@gmail.com>
pkgname=moonphase
pkgver=1.0.0
pkgrel=1
epoch=
pkgdesc="Simple program to print out approximate moon phase"
arch=('x86_64')
url="https://github.com/melkersona/moonphase"
license=('GPL')
groups=()
depends=()
makedepends=()
checkdepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=("https://github.com/melkersona/moonphase/archive/refs/tags/release.tar.gz")
noextract=()
md5sums=()
validpgpkeys=()

prepare() {
	cd "$pkgname-$pkgver"
}

build() {
	cd "$pkgname-$pkgver"
	make
}

check() {
	cd "$pkgname-$pkgver"
}

package() {
	cd "$pkgname-$pkgver"
	make DESTDIR="$pkgdir/" install
}
sha256sums=('1891c9e3d72bffc5dc1b0a15259ed12cbff34f1e09e552cba4c9c8adaa658744')
