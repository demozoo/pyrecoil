from setuptools import setup, find_packages, Extension

recoil_module = Extension('_recoil', sources=['recoil_interface.c', 'recoil.c'])

def readme():
    with open('README.rst') as f:
        return f.read()

setup(
    name="pyrecoil",
    version="0.2",
    packages=find_packages(),
    ext_modules=[recoil_module],
    include_package_data=True,

    author="Matt Westcott",
    author_email="matt@west.co.tt",
    description="Python bindings for RECOIL, the Retro Computer Image Library",
    long_description=readme(),
    classifiers=[
        "Development Status :: 3 - Alpha",
        "Topic :: Multimedia :: Graphics",
        "Topic :: Multimedia :: Graphics :: Graphics Conversion",
        "Programming Language :: Python :: 2",
        "Programming Language :: Python :: 2.7",
        "License :: OSI Approved :: GNU General Public License v2 or later (GPLv2+)",
    ],
    url="http://github.com/gasman/pyrecoil",
    license="GPLv2+",
)
