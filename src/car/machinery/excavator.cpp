#include "excavator.hpp"
#include  <algorithm>
const std::array<std::string, 4> Excavator::m_bucketTypes = {"mud", "tilt", "narrow", "standard"};

bool Excavator::changeBucketType(std::string p_bucketType)
{
    auto it = std::find(m_bucketTypes.begin(), m_bucketTypes.end(), p_bucketType);

    if (it != m_bucketTypes.end()) {
        m_bucket = p_bucketType;
        return true;
    } else {
        return false;
    }

    return 0;
}