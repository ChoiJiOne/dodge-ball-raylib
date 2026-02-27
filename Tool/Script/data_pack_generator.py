import os
import openpyxl

from logger import init_logger
from config import filter_dict_for_dataclass

class DataPackGenerator:
    def __init__(self, config_cls, **kwargs):
        self.config = config_cls(**filter_dict_for_dataclass(config_cls, kwargs))
        self.logger = init_logger(self.config.log_file_path)

    def get_logger(self):
        return self.logger

    def run_generate(self):
        pass
