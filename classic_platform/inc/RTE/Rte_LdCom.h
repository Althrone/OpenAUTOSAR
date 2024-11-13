//Configurable interfaces

/* @SWS_LDCOM_00036 */
// BufReq_ReturnType Rte_LdComCbkCopyTxData_<sn>( const PduInfoType* info, const RetryInfoType* retry, PduLengthType* availableDataPtr )
/* @SWS_LDCOM_00037 */
// void Rte_LdComCbkTpTxConfirmation_<sn>( Std_ReturnType result )
/* @SWS_LDCOM_00038 */
// BufReq_ReturnType Rte_LdComCbkStartOfReception_<sn>( const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr )
/* @SWS_LDCOM_00039 */
// BufReq_ReturnType Rte_LdComCbkCopyRxData_<sn>( const PduInfoType* info, PduLengthType* bufferSizePtr )
/* @SWS_LDCOM_00040 */
// void Rte_LdComCbkTpRxIndication_<sn>( Std_ReturnType result )
/* @SWS_LDCOM_00041 */
// void Rte_LdComCbkRxIndication_<sn>( const PduInfoType* PduInfoPtr )
/* @SWS_LDCOM_00042 */
// Std_ReturnType Rte_LdComCbkTriggerTransmit_<sn>( PduInfoType* PduInfoPtr )
/* @SWS_LDCOM_00053 */
// void Rte_LdComCbkTxConfirmation_<sn>( Std_ReturnType result )