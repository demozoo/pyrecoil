pyrecoil
========

*pyrecoil* provides Python bindings to `RECOIL <http://recoil.sourceforge.net/>`_, the Retro Computer Image Library, allowing you to open over 400 image file formats from retro computers.

Installation
~~~~~~~~~~~~

::

    pip install pyrecoil

``pyrecoil`` is most useful when installed in conjunction with `Pillow <http://pillow.readthedocs.org/>`_, the active fork of the Python Image Library::

    pip install Pillow

Usage
~~~~~

::

    from recoil import RecoilImage

    # load image from disk and decode it:
    img = RecoilImage("foo.lbm")

    # load image from an existing file handle:
    # (filename must still be provided, as a hint to the decoder)
    img = RecoilImage("foo.lbm", f)

    # inspecting properties:
    img.colors  # number of colors used in the image
    > 16

    img.frames  # number of alternating frames (used for 'interlace' / 'gigascreen' effects)
    > 1

    img.size  # return a tuple of (width, height)
    > (320, 200)

    img.original_size  # for images that have been resized to account for non-square pixels
    > (320, 200)

    img.platform
    > 'Amiga'

    # Retrieving pixel data -
    # returns a bytearray consisting of three bytes (r, g, b) for each pixel,
    # in left-to-right, top-to-bottom order
    pixels = img.get_pixels()

    # convert to a PIL / Pillow image object:
    pil_image = img.to_pil()
    pil_image.save('foo.png')

Build notes
~~~~~~~~~~~

The RECOIL library itself is implemented in the `Ć Programming Language <https://github.com/pfusik/cito>`_. For ease of distribution, the generated C output (``recoil.c`` and ``recoil.h``) from the ``cito`` transpiler is included in the package - this, along with ``recoil_interface.c``, forms the Python extension module.

Author
~~~~~~

Matt Westcott - matt@west.co.tt, http://twitter.com/gasmanic
