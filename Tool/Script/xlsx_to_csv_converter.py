import os
import pandas as pd

from logger import init_logger
from config import filter_dict_for_dataclass

class XLSXToCSVConverter:
    def __init__(self, config_cls, **kwargs):
        self.config = config_cls(**filter_dict_for_dataclass(config_cls, kwargs))
        self.logger = init_logger(self.config.log_file_path)

    def run_convert(self):
        xlsx_path = os.path.join(self.config.target_xlsx_path, f"{self.config.target_name}.xlsx")
        csv_path = os.path.join(self.config.output_csv_path, f"{self.config.target_name}.csv")

        sheet_dict = pd.read_excel(xlsx_path, sheet_name=None)
        
        merged_dfs = []
        base_columns = None
        
        for sheet_name, df_sheet in sheet_dict.items():
            if sheet_name.startswith('-'):
                self.logger.info(f"Skipping sheet: {sheet_name}")
                continue
            elif sheet_name.startswith('+'):
                self.logger.info(f"Processing sheet: {sheet_name}")
                if base_columns is None:
                    base_columns = list(df_sheet.columns)
                    merged_dfs.append(df_sheet)
                else:
                    if list(df_sheet.columns) != base_columns:
                        error_msg = f"Sheet '{sheet_name}' header mismatch! Expected: {base_columns}, Got: {list(df_sheet.columns)}"
                        self.logger.error(error_msg)
                        raise ValueError(error_msg)
                    
                    merged_dfs.append(df_sheet.iloc[1:])
            else:
                error_msg = f"Sheet name '{sheet_name}' is invalid. It must start with '+' or '-'."
                self.logger.error(error_msg)
                raise ValueError(error_msg)
                
        if not merged_dfs:
            error_msg = "No valid sheets found to convert."
            self.logger.error(error_msg)
            raise ValueError(error_msg)
            
        final_df = pd.concat(merged_dfs, ignore_index=True)
        
        cols_to_keep = [col for col in final_df.columns if not str(col).startswith('#')]
        final_df = final_df[cols_to_keep]
        
        final_df = final_df.fillna("NaN")
        
        final_df.to_csv(csv_path, index=False, encoding='utf-8')
        self.logger.info(f"Successfully converted to {csv_path}")

    def get_logger(self):
        return self.logger