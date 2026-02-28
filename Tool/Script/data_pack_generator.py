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
        excel_path = os.path.join(self.config.target_path, f"{self.config.target_name}.xlsx")
        if not self.is_valid_excel_file(excel_path):
            return

    def is_valid_excel_file(self, file_path):
        if not os.path.exists(file_path):
            self.logger.error(f"Excel file not found at: {file_path}")
            return False
        self.logger.info(f"Loading Excel file: {file_path}")
        return True