// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#pragma once

#include "CDialogBase.h"

class CIPReputationsDlg : public CDialogBase
{
	DECLARE_DYNAMIC(CIPReputationsDlg)

public:
	CIPReputationsDlg(CWnd* pParent = nullptr);
	virtual ~CIPReputationsDlg();

	void SetAccessManager(QuantumGate::AccessManager* am) noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IPREPUTATIONS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemChangedIPReputationsList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeIP();
	afx_msg void OnEnChangeReputation();
	afx_msg void OnBnClickedSetReputation();
	afx_msg void OnBnClickedResetAll();
	afx_msg void OnBnClickedResetSelected();
	afx_msg void OnBnClickedRefresh();

private:
	void UpdateIPReputationList() noexcept;
	void UpdateControls() noexcept;

private:
	QuantumGate::AccessManager* m_AccessManager{ nullptr };
};
