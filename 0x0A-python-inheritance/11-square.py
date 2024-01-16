#!/usr/bin/python3
"""Defines Rectangle module."""
Rectangle = __import__('9-rectangle').Rectangle


class Square(Rectangle):
    """Square class, inherits from Rectangle."""

    def __init__(self, size):
        """Initialize the square."""
        super().__init__(size, size)

    def __str__(self):
        """String representation of the square."""
        return "[Square] {}/{}".format(self.width, self.height)
