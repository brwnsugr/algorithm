def self.create_or_update_by_user_id(user_id, attr_to_update)
    attr_to_update.merge!({user_id: user_id})
    insert_columns = attr_to_update.keys.map{|k| k.to_s}.join(',')
    insert_values = "?," * (attr_to_update.length)
    duplicate_key_updates_columns = attr_to_update.keys.map{|k| k.to_s}.join(' = ?,')
    duplicate_key_updates_values = attr_to_update.values * 2
    query = build_query_with_attr(insert_columns, insert_values, duplicate_key_updates_columns)
    sanitize_sql_array = [query].concat(duplicate_key_updates_values) 
    sanitized_query = ActiveRecord::Base.send(:sanitize_sql_array, sanitize_sql_array)
    ActiveRecord::Base.connection.update(sanitized_query)
  end

  private
  def self.build_query_with_attr(insert_columns, insert_values, duplicate_key_updates_columns)
    query = "INSERT INTO user_details 
    (
      user_id, 
      marketing_ads_on,
    ( 
      #{insert_columns},
      created_at,
      updated_at
    ) 
    VALUES 
      VALUES 
    (
      ?, 
      ?,
      #{insert_values}
      UTC_TIMESTAMP(),
      UTC_TIMESTAMP()
    )
    ON DUPLICATE KEY UPDATE 
      marketing_ads_on = ?,
      ON DUPLICATE KEY UPDATE 
      #{duplicate_key_updates_columns} = ?,
      updated_at = UTC_TIMESTAMP()"
    sanitized_query = ActiveRecord::Base.send(:sanitize_sql_array, [query, user_id, marketing_ads_on_flag, marketing_ads_on_flag])
    ActiveRecord::Base.connection.update(sanitized_query)
    query
  end
