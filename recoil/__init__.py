import _recoil

class RecoilImage(object):
    def __init__(self, filename, f=None):
        if not _recoil.is_our_file(filename):
            raise ValueError("%s is not a valid RECOIL file" % filename)

        if f is None:
            with open(filename) as _f:
                content = bytearray(_f.read())
        else:
            content = bytearray(f.read())

        self.state = _recoil.new()

        is_valid = _recoil.decode(self.state, filename, content)

        if not is_valid:
            raise ValueError("%s is not a valid RECOIL file" % filename)

    @property
    def colors(self):
        return _recoil.get_colors(self.state)

    @property
    def frames(self):
        return _recoil.get_frames(self.state)

    @property
    def size(self):
        return _recoil.get_size(self.state)

    @property
    def original_size(self):
        return _recoil.get_original_size(self.state)

    @property
    def platform(self):
        return _recoil.get_platform(self.state)

    def get_pixels(self):
        return _recoil.get_pixels(self.state)

    def to_pil(self):
        from PIL import Image
        return Image.frombytes('RGB', self.size, str(self.get_pixels()))
