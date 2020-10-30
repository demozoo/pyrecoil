import math
import os.path
import unittest

from PIL import Image, ImageChops
from recoil import RecoilImage


class TestRecoil(unittest.TestCase):
    def setUp(self):
        self.test_dir = os.path.dirname(os.path.abspath(__file__))
        self.image = RecoilImage(os.path.join(self.test_dir, 'fish.scr'))

    def assertImagesSimilar(self, image1, image2):
        diff = ImageChops.difference(image1, image2).histogram()

        sq = (value * (i % 256) ** 2 for i, value in enumerate(diff))
        sum_squares = sum(sq)
        result = math.sqrt(sum_squares / float(image1.size[0] * image1.size[1]))

        self.assertTrue(result < 1, "Images are too different")

    def test_meta(self):
        self.assertEqual(self.image.colors, 9)
        self.assertEqual(self.image.frames, 1)
        self.assertEqual(self.image.size, (256, 192))
        self.assertEqual(self.image.original_size, (256, 192))
        self.assertEqual(self.image.platform, "ZX Spectrum")

    def test_pixel_data(self):
        pixel_data = self.image.get_pixels()
        self.assertEqual(len(pixel_data), 256 * 192 * 3)
        self.assertEqual(pixel_data[0], 0x00)
        self.assertEqual(pixel_data[1], 0xff)
        self.assertEqual(pixel_data[2], 0xff)

    def test_pil_conversion(self):
        expected_image = Image.open(os.path.join(self.test_dir, 'fish.png'))
        actual_image = self.image.to_pil()
        self.assertImagesSimilar(actual_image, expected_image)
